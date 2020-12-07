#ifndef CSCHEDULE_H
#define CSCHEDULE_H
#include "CEvent.hpp"


class CSchedule 
{
 public:
 CSchedule() = default;
 
 void reset(); //TODO
 //Noch eine Funktion für den Ausgabeoperator 

 private:
 CEvent *Schedule[7][5];



};





#endif
