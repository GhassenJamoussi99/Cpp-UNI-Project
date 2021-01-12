#include "CEvents.hpp"
#include <iomanip>

using namespace std;

static int counter = 0;

void CEvents::addEvent(CEvent *m_Event)
{
  counter++;
  Events.push_back(m_Event); 
}

void CEvents::print()
{
  cout << "Veranstaltungen:" << endl;
  string a = " ";
  for (int i = 0; i < counter; i++)
  {
    CWeekday Day = Events[i]->WeekDay;
    printf("%d: %-10s %3s", i + 1, Events[i]->getDay(Day).c_str(), a.c_str());
    Events[i]->Block->print();
    printf("%3s %-25s %-20s %-5s\n", a.c_str(), Events[i]->Name.c_str(), Events[i]->Teacher->getName().c_str(), Events[i]->Room->getName().c_str());
  }
}