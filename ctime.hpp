#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#include <iostream>

class CTime
{
 public:
   CTime(int Hours, int Minutes, int Seconds=0);
   CTime();
   void print() const;

 private:
   int m_Hours;
   int m_Minutes;
   int m_Seconds;
};

#endif