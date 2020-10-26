#include "CTime.hpp"
#include <iomanip>

using namespace std;

CTime::CTime(int Hours, int Minutes, int Seconds):
Hour(Hours),Minute(Minutes),Second(Seconds)
{}


CTime::CTime()
{
    time_t now = time(0); //Aktuelles Datum / Uhrzeit basierend auf dem aktuellen System

    tm *ltm = localtime(&now);
    //Aktuelle Uhrzeit
    Hour   = ltm->tm_hour;  //Hours
    Minute = ltm->tm_min; //Minutes
    Second = ltm->tm_sec; //Seconds
}

void CTime::print() const
{
    if (Second != 0)
    {
        cout << setfill('0') << setw(2) << Hour << ':' << setw(2) << Minute << ':' << setw(2) << Second;
    }
    else
    {
        cout << setfill('0') << setw(2) << Hour << ':' << setw(2) << Minute;
    }
}
