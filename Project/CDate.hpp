#ifndef CDATE_H
#define CDATE_H
#include <ctime>
#include <iostream>

class CDate
{
public:
    CDate();
    CDate(int m_Days, int m_Months, int m_Years);
    void print() const;
    void setDay(int m_Day) { Day = m_Day; }
    void setMonth(int m_Month) { Month = m_Month; }
    void setYear(int m_Year) { Year = m_Year; }
    ~CDate(){};

private:
    int Day;
    int Month;
    int Year;
};

#endif