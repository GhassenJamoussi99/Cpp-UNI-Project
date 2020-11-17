#ifndef CPERSON_H
#define CPERSON_H

#include "CAddress.hpp"
#include "CDate.hpp"
#include <fstream>
#include <iostream>

class CPerson
{
public:
  CPerson() = default;
  CPerson(std::string m_Name, std::string m_Street,
          std::string m_HouseNr, unsigned m_Zipcode,
          std::string m_City, int m_Day, int m_Month, int m_Year);
  CAddress &getAddress();
  virtual unsigned int getMatrNr() { return 0; }
  friend class CEvent;
  unsigned getID(){return ID;}
  std::string getName() { return Name; }
  virtual void print() const;
  virtual ~CPerson()
  {
    std::cout << "Person " << Name << " wird vernichtet." << std::endl;
  }

protected:
  static unsigned LfNr;
  unsigned ID;
  std::string Name;
  CAddress Address;
  CDate Birthday;
};

#endif