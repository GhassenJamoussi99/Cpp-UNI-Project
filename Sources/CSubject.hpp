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
  CSubject(std::string m_Name,unsigned m_SubjNr,CStudy *m_Study);
  void addEvent(CEvent *m_Event);
  void print();
  ~CSubject()
  {std::cout<<"Studienfach " << Name <<" wird vernichtet."<<endl; }

  private:
   unsigned SubjNr;   //Static
   std::string Name;
   CStudy *Study;
   std::vector<CEvent*> Events; 
   
};


#endif