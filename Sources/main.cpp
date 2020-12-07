#include <iostream>

using namespace std;

#include "CBookings.hpp"

int main()
{
   CBookings Belegungen("belegungen.xml");
   Belegungen(ofPersons); //TODO
   Belegungen(ofStudents); //TODO
   Belegungen(ofTeachers); //TODO
   Belegungen(ofBookings); //TODO
   Belegungen(ofScheduleOfStudents); //TODO
   Belegungen(ofScheduleOfStudies); //TODO
   
   return 0;
}
