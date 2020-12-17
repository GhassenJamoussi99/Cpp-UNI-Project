#ifndef CSCHEDULE_H
#define CSCHEDULE_H
#include "CEvent.hpp"

class CSchedule 
{
 public:
 CSchedule() = default;
 friend std::ostream &operator<<(std::ostream &ostr, CSchedule &Sched);
 friend class CBookings;
 void reset(); 

 private:
 CEvent *Schedule[7][5];
 std::string Titel;
};





#endif
