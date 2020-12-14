#ifndef CSCHEDULE_H
#define CSCHEDULE_H
#include "CEvent.hpp"

class CSchedule 
{
 public:
 CSchedule() = default;
 CSchedule(CEvent *Schedule[7][5],std::string Titel);
 friend std::ostream &operator<<(std::ostream &ostr, CSchedule &a);
 void reset(); //TODO
 //Noch eine Funktion für den Ausgabeoperator 

 private:
 CEvent *Schedule[7][5];
 std::string Titel;



};





#endif
