#include "CBookings.hpp"
#include <fstream>
using namespace std;
#include <regex>

CBookings::CBookings(string str)
{
  ifstream src(str);
  string Zeile;

  if (!src)
  {
    cout << str << " konnte nicht geoffnet werden !" << endl;
    exit(1);
  }
  else
  {
    cout << "Datei wurde erfolgreich eingelesen!" << endl;
    while (getline(src, Zeile))
    {
      Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen
      //cout << Zeile << endl;
      if (Zeile.compare("<room>")==0)
      {
        CRoom *R = new CRoom();
        R->load(src);
        Rooms.push_back(R);
      }
      if (Zeile.compare("<block>")==0)
      {
        CBlock *B = new CBlock();
        B->load(src);
        Blocks.push_back(B);
      }
       if (Zeile.compare("<study>")==0)
      {
        CStudy *S = new CStudy();
        S->load(src);
        Studies.push_back(S);
      }

    }
  }
  
}


void CBookings::print()
{
  cout << Blocks.size() << endl;
  for (int i = 0 ; i<Blocks.size();i++)
  {
   Blocks[i]->print();
   cout << endl;
  }
}
