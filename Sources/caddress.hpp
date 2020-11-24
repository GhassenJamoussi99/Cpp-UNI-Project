#ifndef CADDRESS_H
#define CADDRESS_H
#include <iostream>

class CAddress
{
public:
    CAddress() = default;
    void print() const;
    void setStreet(std::string m_Street){ Street = m_Street;}
    void setHouseNr(std::string m_HouseNr){ HouseNr = m_HouseNr;}
    void setZipcode(unsigned m_Zipcode){ Zipcode = m_Zipcode;}
    void setCity(std::string m_City){ City = m_City;}
    CAddress(std::string m_Street,std::string m_HouseNr,unsigned m_Zipcode,std::string m_City);

    ~CAddress(){};

private:
    std::string Street;
    std::string HouseNr;
    unsigned Zipcode;
    std::string City;
};

#endif