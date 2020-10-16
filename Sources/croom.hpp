#ifndef CROOM_H
#define CROOM_H

#include <string>
#include <iostream>

class CRoom
{
  public:
   CRoom() = default;
   CRoom(std::string m_Name, std::string m_Building , short m_Seats );
   void print() const;
   ~CRoom(){};


  private:
   std::string Name; //or include 'using namespace std'
   std::string Building;
   short Seats;


};

#endif