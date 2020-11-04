#ifndef CSTUDY_H
#define CSTUDY_H

#include <iostream>

class CStudy 
{
 public:
  CStudy() = default;
  void print();

 private:
  std::string Name;
  bool NC;
  short NrOfTerms;

};

#endif
