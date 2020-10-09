#ifndef CDATE_H
#define CDATE_H
#include <ctime>
#include <iostream>

class CDate
{
public:
    CDate(int Days, int Months, int Years); //Abfragen der Eigenschaften
    CDate();
    void print() const; //Ausgeben

private:
    int m_Days;
    int m_Months;
    int m_Years;
};

#endif