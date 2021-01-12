#include "CRoom.hpp"
#include <fstream>
#include <string>
#include <regex>
using namespace std;

CRoom::CRoom(string m_Name, string m_Building, short m_Seats) : Name(m_Name), Building(m_Building), Seats(m_Seats)
{
}

void CRoom::print() const
{
  cout << "Raum " << Name << " (" << Building << ")";
}

void CRoom::load(ifstream& File)
{
  string Zeile;
  int Len;
  while (getline(File, Zeile))
  {
    Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen
    
    if (Zeile == "</room>")
    {
      break;
    }

    if (strncmp(Zeile.c_str(), "<name>", 6) == 0)
    {
      Len = Zeile.length() - (6 + 7); // length von "<name>" und </name> -> 6 + 7
      if (strncmp(Zeile.c_str() + 6 + Len, "</name>", 7) == 0)
      {
        Name=Zeile.substr(6,Len);
      }
    }

     if (strncmp(Zeile.c_str(), "<building>", 10) == 0)
    {
      Len = Zeile.length() - (10 + 11);  
      if (strncmp(Zeile.c_str() + 10 + Len, "</building>", 11) == 0)
      {
        Building = Zeile.substr(10,Len);
      }
    }
     
    
     if (strncmp(Zeile.c_str(), "<seats>", 7) == 0)
    {
      Len = Zeile.length() - (7 + 8);  
      if (strncmp(Zeile.c_str() + 7 + Len, "</seats>", 8) == 0)
      {
        Seats = stoi(Zeile.substr(7,Len));
      }
    } 

  }
}