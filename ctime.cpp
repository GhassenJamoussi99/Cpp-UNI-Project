#include "ctime.hpp"
#include <iomanip>

using namespace std;

CTime::CTime(int Hours, int Minutes, int Seconds)
{
    m_Hours = Hours;
    m_Minutes = Minutes;
    m_Seconds = Seconds;
}

CTime::~CTime()
{
  //printf("Die Uhrzeit %02d.%02d.%02d wird vernichtet\n",m_Hours,m_Minutes,m_Seconds);
}

CTime::CTime()
{
    time_t now = time(0); //Aktuelles Datum / Uhrzeit basierend auf dem aktuellen System

    tm *ltm = localtime(&now);
    //Aktuelle Uhrzeit
    m_Hours = ltm->tm_hour;   //Hours
    m_Minutes = ltm->tm_min;  //Minutes
    m_Seconds = ltm->tm_sec; //Seconds
}

void CTime::print() const
{
    if (m_Seconds != 0)
    { 
        printf("%02d.%02d.%02d",m_Hours,m_Minutes,m_Seconds);

        //cout << setfill('0') << setw(2) << m_Hours << ':' << setw(2) << m_Minutes << ':' << setw(2) << m_Seconds;
    }
    else
    {   
        printf("%02d:%02d:%02d",m_Hours,m_Minutes); 
        //cout << setfill('0') << setw(2) << m_Hours << ':' << setw(2) << m_Minutes ;
    }
}
