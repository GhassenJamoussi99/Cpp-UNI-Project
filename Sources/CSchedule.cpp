#include "CSchedule.hpp"
#include <iomanip>

using namespace std;

ostream &operator<<(ostream &ostr, CSchedule &Sched)
{

  ostr << "\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  ostr << "|     |        Mo        |        Di        |        Mi        |        Do        |        Fr        |\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  string empty = "";
  int count = 0;
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (j == 0)
      {
        ostr << "|     |";
      }
      if (Sched.Schedule[i][j])

        ostr << Sched.Schedule[i][j]->getName() << setfill(' ') << setw(19 - (Sched.Schedule[i][j]->getName()).length()) << "|";
      else
      {
        cout << empty << setfill(' ') << setw(19) << "|";
      }
    }
    ostr << "\n";
    for (int j = 0; j < 5; j++)
    {

      if (j == 0)
      {
        count++;
        ostr << "|  " << count << "  |";
      }
      if (Sched.Schedule[i][j])
        ostr << Sched.Schedule[i][j]->getDozentName() << setfill(' ') << setw(19 - (Sched.Schedule[i][j]->getDozentName()).length()) << "|";
      else
      {
        cout << empty << setfill(' ') << setw(19) << "|";
      }
    }
    ostr << "\n";
    for (int j = 0; j < 5; j++)
    {
      if (j == 0)
      {
        ostr << "|     |";
      }
      if (Sched.Schedule[i][j])
        ostr << Sched.Schedule[i][j]->getRoom() << setfill(' ') << setw(19 - (Sched.Schedule[i][j]->getRoom()).length()) << "|";
      else
      {
        cout << empty << setfill(' ') << setw(19) << "|";
      }
    }
    ostr << "\n|-----|------------------|------------------|------------------|------------------|------------------|" << endl;
  }
  
   ostr << endl;
 
  return ostr;
}

void CSchedule::reset()
{
  cout << "Stundenplan fuer " << Titel << ": \n";

  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      Schedule[i][j] = nullptr;
    }
  }
}
