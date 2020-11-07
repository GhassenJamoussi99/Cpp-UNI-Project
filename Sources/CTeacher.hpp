#ifndef CTEACHER_H
#define CTEACHER_H
#include "CPerson.hpp"

class CTeacher : public CPerson
{
  public:
  CTeacher() = default;
  CTeacher(std::string m_Name, std::string m_Street,
          std::string m_HouseNr, unsigned m_Zipcode,
          std::string m_City, int m_Day, int m_Month, int m_Year,
          int m_PersonalNr);
  //set
  //get
  void print();
  ~CTeacher()
  {std::cout<<"Lehrer*in " << Name <<" wird vernichtet."<<endl; }

  private:
   unsigned PersonalNr;


};



#endif