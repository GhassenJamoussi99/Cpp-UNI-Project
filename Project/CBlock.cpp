#include "CBlock.hpp"
#include <iomanip>
#include <regex>
using namespace std;

CBlock::CBlock(short m_BlockNr, CTime m_Begin) : BlockNr(m_BlockNr), Begin(m_Begin.Hour, m_Begin.Minute)
{}

CTime CBlock::getEnd()
{
  CTime Ende;

  Ende = Begin + 90;

  return Ende;
}

void CBlock::print()
{
  int HBegin = Begin.Hour;
  int MBegin = Begin.Minute;

  cout << setfill('0') << setw(2) << Begin.Hour << ":" << setw(2) << Begin.Minute << " - ";
 
  CTime Ende;
  Ende = getEnd();

  cout << setfill('0') << setw(2) << Ende.Hour << ":" << setw(2) << Ende.Minute;

  Begin.Hour = HBegin;
  Begin.Minute = MBegin;
}

void CBlock::load(ifstream &File)
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