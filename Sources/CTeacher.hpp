#ifndef CTEACHER_H
#define CTEACHER_H
#include "CPerson.hpp"

class CTeacher : public CPerson
{
  public:
  CTeacher() = default;
  //set
  //get
  void print();
  ~CTeacher()
  {std::cout<<"Lehrer*in " << Name <<" wird vernichtet."<<endl; }

  private:
   unsigned PersonalNr;


};



#endif