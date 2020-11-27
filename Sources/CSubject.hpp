#ifndef CSUBJECT_H
#define CSUBJECT_H

#include <iostream>
#include "CStudy.hpp"
#include "CEvent.hpp"
#include <vector>

class CBookings;

class CSubject
{
public:
  CSubject() = default;
  CSubject(std::string m_Name, unsigned m_SubjNr, CStudy *m_Study);
  void addEvent(CEvent *m_Event);
  void print();
  void load(std::ifstream &File, CBookings &subj);
  std::string getName() { return Name; }
  void setName(std::string m_Name) { Name = m_Name; }
  void setSubjNr(unsigned m_SubjNr) { SubjNr = m_SubjNr; }
  std::string getStudyName() { return Study->getStudy(); }
  void setStudyName(std::string m_Study) { Study->setStudy(m_Study); }
  std::string getSubject() { return Name; }
  ~CSubject()
  {
    std::cout << "   Studienfach " << Name << " wird vernichtet." << std::endl;
  }

private:
  unsigned SubjNr;
  std::string Name;
  CStudy *Study ;
  std::vector<CEvent *> Events;
};

#endif