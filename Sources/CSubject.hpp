#ifndef CSUBJECT_H
#define CSUBJECT_H

#include <iostream>
#include "CStudy.hpp"
#include "CEvent.hpp"
#include <vector>

class CSubject
{
  public:
  CSubject() = default;
  void addEvent(CEvent *m_Event);
  void print();

  private:
   static unsigned SubjNr;
   std::string Name;
   CStudy *Study;
   std::vector<CEvent*> Events;

};


#endif