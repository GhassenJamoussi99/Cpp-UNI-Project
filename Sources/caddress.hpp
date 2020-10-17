#ifndef CADDRESS_H
#define CADDRESS_H
#include <iostream>

class CAddress
{
public:
    CAddress() = default;
    void print() const;
    friend class CPerson;
    CAddress(std::string m_Street,std::string m_HouseNr,unsigned m_Zipcode,std::string m_City);

    ~CAddress(){};

private:
    std::string Street;
    std::string HouseNr;
    unsigned Zipcode;
    std::string City;
};

#endif