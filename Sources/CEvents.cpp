#include "CEvents.hpp"
#include <iomanip>

using namespace std;

static int counter = 0;

void CEvents::addEvent(CEvent *m_Event)
{
  counter++;
  Events.push_back(m_Event); //Works correctly but see why.
}

extern "C" void CEvents::print()
{
  cout << "Veranstaltungen:" << endl ;

  for (int i = 0 ; i < counter;i++)
  {
    CWeekday Day = Events[i]->WeekDay;
    printf("%d: %s",i+1,Events[i]->getDay(Day).c_str() );
    Events[i]->Block->print(); 
    printf("%25s %20s %10s\n",Events[i]->Name.c_str(),Events[i]->Teacher->Name.c_str(),Events[i]->Room->Name.c_str());
  }
  

}