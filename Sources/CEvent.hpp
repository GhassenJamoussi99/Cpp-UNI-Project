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
    CEvent(std::string m_Name, CPerson *m_Block, CRoom *m_Room,
           CWeekday m_day, short m_Period);
    void print();
    ~CEvent(){};

private:
    std::string Name;
    CBlock *Block;
    CRoom *Room;
    CWeekday WeekDay;
    short Period;
};

#endif
