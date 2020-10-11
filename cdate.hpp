#ifndef CDATE_H
#define CDATE_H
#include <ctime>
#include <iostream>

class CDate
{
public:
    CDate(); // Standardkonstruktor
    CDate(int Days, int Months, int Years); //Abfragen der Eigenschaften : Konstruktor 
    ~CDate();  //Destruktor           
    void print() const; //Ausgabe

private:
    int m_Days;
    int m_Months;
    int m_Years;
};

#endif