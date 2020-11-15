#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#include <iostream>

class CTime
{
 public:
  CTime() ;  //Standardkonstruktor
  CTime(int m_Hours, int m_Minutes, int m_Seconds = 0); //Konstruktor
  friend class CBlock;
  friend class CBooking;
  ~CTime(){}; //Destruktor
  void print() const;

 private:
  int Hour;   
  int Minute;  
  int Second; 
};

#endif