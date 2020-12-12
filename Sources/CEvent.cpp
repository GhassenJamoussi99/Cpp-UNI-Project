#include "CEvent.hpp"
#include <regex>
#include "CSubject.hpp"
#include "CBookings.hpp"
using namespace std;

CEvent::CEvent(string m_Name,
               CPerson *m_Teacher,
               CRoom *m_Room,
               CBlock *m_Block,
               CWeekday m_day,
               short m_Period) : Name(m_Name), Teacher(m_Teacher),
                                 Room(m_Room), Block(m_Block), WeekDay(m_day),
                                 Period(m_Period)
{
}

CWeekday CEvent::StringToEnum(string str)
{

    if (str == "Mo")
        return Mo;
    else if (str == "Di")
        return Di;
    else if (str == "Mi")
        return Mi;
    else if (str == "Do")
        return Do;
    else if (str == "Fr")
        return Fr;
    else if (str == "Sa")
        return Sa;
    else
        return So;
}

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

void CEvent::loadEvent(ifstream &File, CBookings &subj)
{
    string Zeile;
    int Len;
    while (getline(File, Zeile))
    {
        Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

        if (Zeile == "</event>")
        {
            break;
        }
       
        EVNTS++;

        if (strncmp(Zeile.c_str(), "<name>", 6) == 0)
        {
            Len = Zeile.length() - (6 + 7);
            if (strncmp(Zeile.c_str() + 6 + Len, "</name>", 7) == 0)
            {
                Name = Zeile.substr(6, Len);
            }
        }

        if (strncmp(Zeile.c_str(), "<teacher>", 9) == 0)
        {
            Len = Zeile.length() - (9 + 10);
            if (strncmp(Zeile.c_str() + 9 + Len, "</teacher>", 10) == 0)
            {
                Teacher = subj.findTeacher(Zeile.substr(9, Len));
            }
        }

        if (strncmp(Zeile.c_str(), "<room>", 6) == 0)
        {

            Len = Zeile.length() - (6 + 7);
            if (strncmp(Zeile.c_str() + 6 + Len, "</room>", 7) == 0)
            {
                Room = subj.findRoom(Zeile.substr(6, Len));
            }
        }

        if (strncmp(Zeile.c_str(), "<block>", 7) == 0)
        {
            Len = Zeile.length() - (7 + 8);
            if (strncmp(Zeile.c_str() + 7 + Len, "</block>", 8) == 0)
            {
                Block = subj.findBlock(stoi(Zeile.substr(7, Len)));
            }
        }

        if (strncmp(Zeile.c_str(), "<weekday>", 9) == 0)
        {
            Len = Zeile.length() - (9 + 10);
            if (strncmp(Zeile.c_str() + 9 + Len, "</weekday>", 10) == 0)
            {
                WeekDay = StringToEnum(Zeile.substr(9, Len));
            }
        }

        if (strncmp(Zeile.c_str(), "<period>", 8) == 0)
        {
            Len = Zeile.length() - (8 + 9);
            if (strncmp(Zeile.c_str() + 8 + Len, "</period>", 9) == 0)
            {
                Period = stoi(Zeile.substr(8, Len));
            }
        }
    }
}