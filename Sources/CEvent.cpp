#include "CEvent.hpp"

using namespace std;

CEvent::CEvent(string m_Name,
             CPerson *m_Teacher,
             CRoom m_Room,
             CBlock m_Block,
             CWeekday m_day, 
             short m_Period) : Name(m_Name),Teacher(m_Teacher),
                               Room(m_Room),Block(m_Block),WeekDay(m_day),
                               Period(m_Period)
{}

string CEvent::getDay(CWeekday m_WeekDay)
{
   switch (m_WeekDay)
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