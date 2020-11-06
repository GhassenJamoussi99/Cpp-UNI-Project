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
    CBooking(CSubject *m_Subject,CStudent *m_Student,int m_Day,int m_Month,int m_Year,
             int m_Hour,int m_Minute,int m_Second);
    void print();
    ~CBooking()
    {std::cout<<"Belegung Nr. " << BookingNr <<" wird vernichtet."<<endl; }

 private:
    static unsigned BookingNr;
    CSubject *Subject;
    CStudent *Student;
    CDate BookingDate;
    CTime BookingTime;
};

#endif
