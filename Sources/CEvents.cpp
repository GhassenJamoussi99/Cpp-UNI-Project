#include "CEvents.hpp"
using namespace std;



CEvent CEvent::addEvent(CEvent *m_Event)
{
  Events.push_back(m_Event); //à revoir weird shit.
}

