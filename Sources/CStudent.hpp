#ifndef CSTUDENT_H
#define CSTUDENT_H
#include "CStudy.hpp"
#include "CPerson.hpp"
#include <fstream>

class CBookings;

class CStudent : virtual public CPerson  //Auf virtual public setzen, um Diamond of Death zu vermeiden
{
public:
  CStudent() = default;
  CStudent(std::string m_Name, std::string m_Street,
           std::string m_HouseNr, unsigned m_Zipcode,
           std::string m_City, int m_Day, int m_Month, int m_Year,
           unsigned int m_MatriculationNr, unsigned short m_Term, unsigned m_Credits,
           CStudy *m_Study);
  void load(std::ifstream &File, CBookings &subj);
  virtual unsigned int getPersonalNr(){return 0;}
  std::string getName() { return this->Name; }
  void setName(std::string m_Name) { Name = m_Name; }
  void setMatrNr(unsigned int m_MatrNr) { MatriculationNr = m_MatrNr; }
  void setBirthday(CDate m_Birthday) { Birthday = m_Birthday; }
  void setID(unsigned int m_ID) { ID = m_ID; }
  CDate getBirthday() { return this->Birthday; }
  unsigned int getMatrNr() { return this->MatriculationNr; }
  virtual void print(); //..
  ~CStudent()
  {
    std::cout << "   Student*in " << Name << " wird vernichtet." << std::endl;
  }

protected:
  unsigned int MatriculationNr;
  unsigned short Term;
  unsigned Credits;
  CStudy *Study;
};

#endif
