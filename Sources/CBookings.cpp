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
      if (Zeile.compare("<room>") == 0)
      {
        CRoom *R = new CRoom();
        R->load(src);
        Rooms.push_back(R);
      }
      if (Zeile.compare("<block>") == 0)
      {
        CBlock *B = new CBlock();
        B->load(src);
        Blocks.push_back(B);
      }
      if (Zeile.compare("<study>") == 0)
      {
        CStudy *S = new CStudy();
        S->load(src);
        Studies.push_back(S);
      }

      if (Zeile.compare("<student>") == 0)
      {
        CStudent *S1 = new CStudent();
        S1->load(src);
        Persons.push_back(S1);
      }

      if (Zeile.compare("<teacher>") == 0)
      {
        CTeacher *T1 = new CTeacher();
        T1->load(src);
        Persons.push_back(T1);
      }

      if (Zeile.compare("<subject>") == 0)
      {
        cout << "azbi ?"<< endl;
        CSubject *S = new CSubject();
        S->load(src);
        Subjects.push_back(S);
      }
    }
  }
}

void CBookings::print()
{
  cout << "Subject's size" << Subjects.size() << endl;
  cout << " Event's size " << Subjects[0]->Events.size() << endl;
  /*for (int i = 0; i < Subjects.size(); i++)
  {
    for (int j = 0; j < (Subjects[i]->Events).size(); i++)
    {
      cout << "Event Nr." << j + 1 << endl;
      cout << "name of the Event " << Subjects[i]->Events[j]->Name << endl;
      cout << "Teacher's name " << Subjects[i]->Events[j]->Teacher->getName() << endl;
      cout << "\nRoom's name " << Subjects[i]->Events[j]->Room->getName();
      cout << "\nBlocks's name " << Subjects[i]->Events[j]->Room->getName();
      cout << "\nDay :  " << Subjects[i]->Events[j]->WeekDay;
      cout << "\nPeriod :" << Subjects[i]->Events[j]->Period;
    }
  }
  */
}
