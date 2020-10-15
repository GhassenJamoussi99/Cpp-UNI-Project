#ifndef CDATE_H
#define CDATE_H
#include <ctime>
#include <iostream>

class CDate
{
public:
    CDate(); // Standardkonstruktor
    CDate(int m_Days, int m_Months, int m_Years); //Abfragen der Eigenschaften : Konstruktor 
    void print() const;
    friend class CPerson;
    ~CDate(){};  //Destruktor           

private:
    int Day;   
    int Month; 
    int Year;  
};

#endif