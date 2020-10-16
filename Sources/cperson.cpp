#include "cperson.hpp"
using namespace std;

CPerson::CPerson(
    string m_Name,
    string m_Street,
    string m_HouseNr,
    unsigned m_Zipcode,
    string m_City,
    int m_Day, int m_Month, int m_Year)
{
    Name = m_Name;
    Address.Street = m_Street;
    Address.HouseNr = m_HouseNr;
    Address.Zipcode = m_Zipcode;
    Address.City = m_City;
    Birthday.Day = m_Day;
    Birthday.Month = m_Month;
    Birthday.Year = m_Year;
}

void CPerson::print() const
{
    cout << Name << " (* " << Birthday.Day << "." << Birthday.Month << "." << Birthday.Year << ")";
}

 CAddress &CPerson::getAddress()
{
    return this->Address;
}
