#include "cdate.hpp"
#include <iomanip>
//#include <cstdio>

using namespace std;

CDate::CDate(int Days, int Months, int Years)
{
   m_Days = Days;
   m_Months = Months;
   m_Years = Years;
}

CDate::~CDate()
{
  //printf("Das Datum %02d.%02d.%02d wird vernichtet\n",m_Days,m_Months,m_Years);
}

CDate::CDate()
{
   time_t now = time(0);   //Aktuelles Datum / Uhrzeit basierend auf dem aktuellen System

   tm *ltm = localtime(&now); //struct ltm
   //Aktuelles Datum
   m_Days = ltm->tm_mday;
   m_Months = 1 + ltm->tm_mon;
   m_Years = 1900 + ltm->tm_year;
}

void CDate::print() const
{
   printf("%02d.%02d.%02d",m_Days,m_Months,m_Years);
   //cout << setfill('0') << setw(2) << m_Days << '.' << setw(2) << m_Months << '.' << setw(2) << m_Years; //setfill('0') und setw(2) ist wie %02i im C 
}

