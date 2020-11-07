#include "CTeacher.hpp"

using namespace std;

CTeacher::CTeacher(string m_Name, string m_Street,
          string m_HouseNr, unsigned m_Zipcode,
          string m_City, int m_Day, int m_Month, int m_Year,
          int m_PersonalNr)
         : CPerson(m_Name,m_Street,m_HouseNr,m_Zipcode,m_City,m_Day,m_Month,m_Year),
           PersonalNr(m_PersonalNr)
 {}