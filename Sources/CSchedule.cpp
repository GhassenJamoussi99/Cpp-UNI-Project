#include "CSchedule.hpp"
#include <iomanip>

using namespace std;

ostream &operator<<(ostream &ostr, CSchedule &Sched)
{

  ostr << "\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  ostr << "|     |        Mo        |        Di        |        Mi        |        Do        |        Fr        |\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  //Check with output.cpp whether you can use the array with pointers DONE
  string empty = "";

  //Implementation : use FACH , DOZENT , RAUM in just one single array DONE
  // Called CEvent and then call them with the schedule constructor here in DONE
  // this operator , so that we can overload the schedule each time we want to use it DONE
  // remove everything from CBookings related to the ouput of Schedules
  // and adapt them here in this function
  int count = 0;
  ostr << Sched.Schedule[0][4]->getRoom();
  /*for (int i = 0; i < 7; i++)
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
 */
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
