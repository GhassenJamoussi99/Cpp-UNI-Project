#include "ctime.hpp"
#include <iomanip>

using namespace std;

CTime::CTime(int Hours, int Minutes, int Seconds)
{
    m_Hours = Hours;
    m_Minutes = Minutes;
    m_Seconds = Seconds;
}

CTime::CTime()
{
    time_t now = time(0);

    tm *ltm = localtime(&now);

    m_Hours = ltm->tm_hour;
    m_Minutes = ltm->tm_min;
    m_Seconds = ltm->tm_sec;
}

void CTime::print() const
{
    if (m_Seconds != 0)
    {
        cout << setfill('0') << setw(2) << m_Hours << ':' << setw(2) << m_Minutes << ':' << setw(2) << m_Seconds;
    }
    else
    {
        cout << setfill('0') << setw(2) << m_Hours << ':' << setw(2) << m_Minutes ;
    }
}
