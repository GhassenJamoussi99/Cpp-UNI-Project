#ifndef CSTUDY_H
#define CSTUDY_H
#include <fstream>
#include <iostream>


class CStudy 
{
 public:
  CStudy() = default;
  CStudy(std::string m_Name, bool m_NC, short m_NrOfTerms);
  std::string getStudy(){return Name;}
  void print() const;
  friend class CStudent;
  void load(std::ifstream& File);
  ~CStudy()
  {std::cout<<"Studiengang " << Name <<" wird vernichtet."<<std::endl; }

 private:
  std::string Name;
  bool NC;
  short NrOfTerms;

};

#endif
