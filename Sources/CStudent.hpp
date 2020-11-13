#ifndef CSTUDENT_H
#define CSTUDENT_H
#include "CStudy.hpp"
#include "CPerson.hpp"

class CStudent : public CPerson
{
 public:
  CStudent() = default;
  CStudent(std::string m_Name, std::string m_Street,
           std::string m_HouseNr, unsigned m_Zipcode,
           std::string m_City, int m_Day, int m_Month, int m_Year,
           unsigned int m_MatriculationNr, unsigned short m_Term, unsigned m_Credits,
           CStudy *m_Study);

  std::string getName() { return this->Name; }
  CDate getBirthday() { return this->Birthday; }
  unsigned int getMatrNr() { return this->MatriculationNr; }
  void getStudy(){Study->print();}
  void print();
  ~CStudent()
  {
    std::cout << "Student*in " << Name << " wird vernichtet." << std::endl;
  }

 private:
  unsigned int MatriculationNr;
  unsigned short Term;
  unsigned Credits;
  CStudy *Study;
};

#endif