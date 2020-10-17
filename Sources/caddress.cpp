#include "caddress.hpp"
#include "cperson.hpp"
using namespace std;

void CAddress::print() const
{
   cout << Street << " " << HouseNr << endl;
   cout << Zipcode << " " << City;
}

CAddress::CAddress(std::string m_Street, std::string m_HouseNr, unsigned m_Zipcode, std::string m_City)
{
   this->Street = m_Street;
   this->HouseNr = m_HouseNr;
   this->Zipcode = m_Zipcode;
   this->City = m_City;
}
