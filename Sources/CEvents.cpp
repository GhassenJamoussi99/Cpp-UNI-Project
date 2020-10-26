#include "CEvents.hpp"
using namespace std;

static int counter = 0;

void CEvents::addEvent(CEvent *m_Event)
{
  counter++;
  Events.push_back(m_Event); //à revoir weird shit.
}

/*extern "C" */void CEvents::print()
{
  for (int i = 0 ; i < counter;i++)
  {
    printf("%d: %s",i+1,Events[i]->getDay() );
    Events[i]->Block->print(); 
    printf("%5s %5s %5s",Events[i]->Name,Events[i]->Teacher->Name,Events[i]->Room->Name);

  }
  

}