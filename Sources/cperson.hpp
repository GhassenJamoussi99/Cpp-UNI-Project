#ifndef CPERSON_H
#define CPERSON_H

#include "CAddress.hpp"
#include "CDate.hpp"
#include <iostream>

class CPerson
{
public:
  CPerson() = default;
  CPerson(std::string m_Name, std::string m_Street,
          std::string m_HouseNr, unsigned m_Zipcode,
          std::string m_City, int m_Day, int m_Month, int m_Year);
  CAddress &getAddress();
  friend class CEvents;
  void print() const;
  ~CPerson(){};

protected:
  static unsigned ID;
  std::string Name;
  CAddress Address;
  CDate Birthday;
};

#endif