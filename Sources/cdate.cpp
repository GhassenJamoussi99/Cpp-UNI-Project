#include "cdate.hpp"
#include <iomanip>

using namespace std;

CDate::CDate(int m_Days, int m_Months, int m_Years)
{
   Day = m_Days;
   Month = Month;
   Year = Year;
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

