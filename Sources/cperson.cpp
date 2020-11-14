#include "CPerson.hpp"
#include <regex>
using namespace std;

unsigned CPerson::LfNr = 0;


CPerson::CPerson(
    string m_Name,
    string m_Street,
    string m_HouseNr,
    unsigned m_Zipcode,
    string m_City,
    int m_Day, int m_Month, int m_Year) 
    :Address(m_Street,m_HouseNr,m_Zipcode,m_City),Birthday(m_Day,m_Month,m_Year)
{
    Name = m_Name;
    ID=++LfNr;
}

void CPerson::print() const
{
    cout << Name << " (* " ;
    Birthday.print();
    cout << ")";
}

 CAddress &CPerson::getAddress()
{
    return this->Address;
}

void CPerson::load(ifstream &File)
{
  string Zeile;
  int Len;
  while (getline(File, Zeile))
  {
    Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

    if (Zeile == "</block>")
    {
      break;
    }

    if (strncmp(Zeile.c_str(), "<blocknr>", 9) == 0)
    {
      Len = Zeile.length() - (9 + 10);
      if (strncmp(Zeile.c_str() + 9 + Len, "</blocknr>", 10) == 0)
      {
        BlockNr = stoi(Zeile.substr(9, Len));
      }
    }

    if (strncmp(Zeile.c_str(), "<begin>", 7) == 0)
    {
      while (getline(File, Zeile))
      {
        Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

        if (Zeile == "</begin>")
        {
          break;
        }

        if (strncmp(Zeile.c_str(), "<hour>", 6) == 0)
        {
          Len = Zeile.length() - (6 + 7);
          if (strncmp(Zeile.c_str() + 6 + Len, "</hour>", 7) == 0)
          {
            Begin.Hour = stoi(Zeile.substr(6, Len));
            Begin.Minute = 0;
          }
        }

        if (strncmp(Zeile.c_str(), "<minute>", 8) == 0)
        {
          Len = Zeile.length() - (8 + 9);
          if (strncmp(Zeile.c_str() + 8 + Len, "</minute>", 7) == 0)
          {
            Begin.Minute = stoi(Zeile.substr(8, Len));
          }
        }
      }
    }
  }
}
