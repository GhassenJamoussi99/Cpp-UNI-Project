#include "CEvent.hpp"

using namespace std;

CEvent::CEvent(string m_Name,
             CPerson *m_Teacher,
             CRoom *m_Room,
             CBlock *m_Block,
             CWeekday m_day, 
             short m_Period) 
{
    Name
}

string CEvent::getDay()
{
   switch (WeekDay)
   {
    case Mo:
        return "Montag";
    case Di:
        return "Dienstag";
    case Mi:
        return "Mittwoch";
    case Do:
        return "Donnerstag";
    case Fr:
        return "Freitag";
    case Sa:
        return "Samstag";
    case So:
        return "Sonntag";

    default:
        return "None";
   }
}