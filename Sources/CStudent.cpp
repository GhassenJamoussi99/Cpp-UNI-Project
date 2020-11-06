#include "CStudent.hpp"
using namespace std;


CStudent::CStudent(string m_Name, string m_Street,
          string m_HouseNr, unsigned m_Zipcode,
          string m_City, int m_Day, int m_Month, int m_Year,
          unsigned int m_MatriculationNr,unsigned short m_Term,unsigned m_Credits,
          CStudy *m_Study): 
          CPerson(m_Name,m_Street,m_HouseNr,m_Zipcode,m_City,m_Day,m_Month,m_Year),
           MatriculationNr(m_MatriculationNr),Term(m_Term),Credits(m_Credits),Study(m_Study)
          {}

          