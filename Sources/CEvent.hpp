#ifndef CEVENT_H
#define CEVENT_H
#include <iostream>
#include <fstream>
#include "CBlock.hpp"
#include "CRoom.hpp"
#include "CPerson.hpp"

enum CWeekday
{
    Mo,
    Di,
    Mi,
    Do,
    Fr,
    Sa,
    So
};

class CEvent
{
public:
    CEvent() = default;
    CEvent(std::string m_Name, CPerson *Teacher, CRoom *m_Room, CBlock *m_Block,
           CWeekday m_day, short m_Period);
    std::string getDay(CWeekday m_WeekDay);
    CWeekday StringToEnum(std::string str);
    void loadEvent(std::ifstream &File);
    friend class CEvents;
    friend class CBookings;
    friend class CSubject;
    ~CEvent(){}; 

private:
    std::string Name;
    CPerson *Teacher;
    CRoom *Room;
    CBlock *Block;
    CWeekday WeekDay;
    short Period;
};

#endif
