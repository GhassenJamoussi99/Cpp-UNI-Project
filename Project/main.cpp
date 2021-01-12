#include <iostream>

using namespace std;

#include "CBookings.hpp"

int main()
{
   CBookings Belegungen("belegungen.xml");
   Belegungen(ofPersons); 
   Belegungen(ofStudents); 
   Belegungen(ofTeachers); 
   Belegungen(ofBookings); 
   Belegungen(ofScheduleOfStudents); 
   Belegungen(ofScheduleOfStudies); 
   
   return 0;
}
