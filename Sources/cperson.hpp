#ifndef CPERSON_H
#define CPERSOn_H
#include "caddress.hpp"
#include "cdate.hpp"
#include <iostream>

class CPerson
{
public:
  CPerson();
  CPerson(std::string m_Name, std::string m_Street,
          std::string m_HouseNr, unsigned m_Zipcode,
          std::string m_City, int m_Day, int m_Month, int m_Year);
  CAddress getAddress();
  void print() const;
  ~CPerson(){};

private:
  unsigned ID;
  std::string Name;
  CAddress Address;
  CDate Birthday;
};


#endif