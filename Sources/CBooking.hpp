#ifndef CBOOKING_H
#define CBOOKING_H

#include "CSubject.hpp"
#include "CDate.hpp"
#include <fstream>
#include "CStudent.hpp"
#include "CTime.hpp"

static unsigned TMP = 0;

class CBooking
{
 public:
    CBooking() = default;
    CBooking(CSubject *m_Subject,CStudent *m_Student,int m_Day,int m_Month,int m_Year,
             int m_Hour,int m_Minute,int m_Second);
    void print();
    friend class CBookings;
    void load(std::ifstream& File);
    ~CBooking()
    {
       TMP++;
       std::cout<<"   Belegung Nr. " << TMP <<" wird vernichtet."<<std::endl; 
    }

 private:
    static unsigned BookingNr;
    CSubject *Subject = new CSubject();
    CStudent *Student = new CStudent();
    CDate BookingDate;
    CTime BookingTime;
};

#endif
