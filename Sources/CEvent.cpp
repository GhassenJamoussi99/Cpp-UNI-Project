#include "CEvent.hpp"
using namespace std;

CEvent::CEvent(string m_Name,
               CPerson *m_Block,
               CRoom *m_Room,
               CWeekday m_day,
               short m_Period)
{
    Name = m_Name;
    *Block = *m_Block; 
    *Room  = *m_Room;
    WeekDay = m_day;
    Period = m_Period;
}

