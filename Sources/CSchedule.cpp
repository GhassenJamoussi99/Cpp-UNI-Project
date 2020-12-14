#include "CSchedule.hpp"

using namespace std;

ostream &operator<<(ostream &ostr , CSchedule &a)
{

  a.reset(); //resetting the schedule 
  
  ostr << "\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  ostr << "|     |        Mo        |        Di        |        Mi        |        Do        |        Fr        |\n";
  ostr << "|-----|------------------|------------------|------------------|------------------|------------------|\n";
  //Check with output.cpp whether you can use the array with pointers  
  //Implementation : use FACH , DOZENT , RAUM in just one single array 
  // Called CEvent and then call them with the schedule constructor here in
  // this operator , so that we can overload the schedule each time we want to use it
  // remove everything from CBookings related to the ouput of Schedules 
  // and adapt them here in this function 
 

}



void CSchedule::reset()
{  
  //Title angeben 
  //Das Array mit nullptr-Zeigern ausfüllen

  cout << Titel << endl;

  for (int i = 0 ; i < 7; i ++)
  {
    for (int j = 0 ; j < 5 ; j++)
    {
       Schedule[i][j] = nullptr;
    }
  }

  
}
