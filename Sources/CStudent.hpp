#ifndef CSTUDENT_H
#define CSTUDENT_H
#include "CStudy.hpp"
#include "CPerson.hpp"

class CStudent : public CPerson
{ 

 public:
  CStudent() = default;
  //get
  //set
  void print();
 

 private:
  unsigned int MatriculationNr;
  unsigned short Term;
  unsigned Credits;
  CStudy *Study;


};



#endif