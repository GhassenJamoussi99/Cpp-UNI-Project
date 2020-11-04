#ifndef CBOOKING_H
#define CBOOKING_H

#include "CSubject.hpp"
#include "CDate.hpp"
#include "CStudent.hpp"
#include "CTime.hpp"

class CBooking
{
 public:
    CBooking() = default;
    void print();

 private:
    static unsigned BookingNr;
    CSubject *Subject;
    CStudent *Student;
    CDate BookingDate;
    CTime BookingTime;
};

#endif
