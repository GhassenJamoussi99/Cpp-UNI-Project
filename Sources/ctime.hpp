#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#include <iostream>

class CTime
{
 public:
  CTime();                                              //Standardkonstruktor
  CTime(int m_Hours, int m_Minutes, int m_Seconds = 0); //Konstruktor
  friend class CBlock;
  void setHour(int m_Hour) { Hour = m_Hour; }
  friend CTime operator+(CTime &T, int a);
  friend CTime operator-(CTime &T, int a);

  void setMinute(int m_Minute) { Minute = m_Minute; }
  void setSecond(int m_Second) { Second = m_Second; }
  ~CTime(){}; //Destruktor
  void print() const;

private:
  int Hour;
  int Minute;
  int Second;
};

#endif