#ifndef CEVENT_H
#define CEVENT_H
#include <iostream>
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
    CEvent(std::string m_Name,CBlock *m_Block, CPerson *Teacher, CRoom *m_Room,
           CWeekday m_day, short m_Period);
    std::string getDay();
    friend class CEvents;

    void print();
    ~CEvent(){};

private:
    std::string Name;
    CBlock *Block;
    CRoom *Room;
    CPerson *Teacher;
    CWeekday WeekDay;
    short Period;
};

#endif
