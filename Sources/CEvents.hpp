#ifndef CEVENTS_H
#define CEVENTS_H
#include <iostream>
#include <vector>


class CEvent
{
 public:
    CEvent() = default;
    CEvent addEvent(CEvent *m_Event);
    void print() const;
    ~CEvent(){};

 private:
    std::vector<CEvent*> Events;
};

#endif
