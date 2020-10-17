#include "cdate.hpp"
#include <iomanip>

using namespace std;

CDate::CDate(int m_Day, int m_Month, int m_Year)
{
   Day = m_Day;
   Month = m_Month;
   Year = m_Year;
}

CDate::CDate()
{
   time_t now = time(0);   //Aktuelles Datum / Uhrzeit basierend auf dem aktuellen System

   tm *ltm = localtime(&now); //struct ltm
   //Aktuelles Datum
   Day = ltm->tm_mday;
   Month = 1 + ltm->tm_mon;
   Year = 1900 + ltm->tm_year;
}

void CDate::print() const
{
  cout << setfill('0') << setw(2) << Day << '.' << setw(2) << Month << '.' << setw(2) << Year;  
}

