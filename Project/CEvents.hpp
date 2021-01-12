#ifndef CEVENTS_H
#define CEVENTS_H
#include <iostream>
#include <vector>
#include "CEvent.hpp"

class CEvents
{
public:
   CEvents() = default;
   void addEvent(CEvent *m_Event);
   void print();
   ~CEvents(){};

protected:
   std::vector<CEvent*> Events;
};

#endif
