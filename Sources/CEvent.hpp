#ifndef CEVENT_H
#define CEVENT_H
#include <iostream>
#include <fstream>
#include "CBlock.hpp"
#include "CRoom.hpp"
#include "CPerson.hpp"
#include "CTeacher.hpp"

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

class CBookings;

class CEvent
{
public:
    CEvent() = default;
    CEvent(std::string m_Name, CPerson *Teacher, CRoom *m_Room, CBlock *m_Block,
           CWeekday m_day, short m_Period);
    std::string getDay(CWeekday m_WeekDay);
    CWeekday StringToEnum(std::string str);
    int getBlock(){return Block->BlockNr;}
    int getWeekDay(){return WeekDay;}
    void setFachName(std::string str){ Name = str;}
    void setDozentName(CPerson *D)
    {
         Teacher = D;
    }
    void setRaumName(CRoom *R)
    { 
         Room = R;
    }
    std::string getRoom(){return Room->getName();}
    std::string getName(){return Name;}
    std::string  getDozentName() {return Teacher->getName();}
    void loadEvent(std::ifstream &File, CBookings &subj);
    
    friend class CEvents;
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
