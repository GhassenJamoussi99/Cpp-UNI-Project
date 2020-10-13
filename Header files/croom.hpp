#ifndef CROOM_H
#define CROOM_H

#include <string>
#include <iostream>

class CRoom
{
  public:
   CRoom();
   void printf() const;
   ~CRoom(){};


  private:
   std::string Name; //or include 'using namespace std'
   std::string Building;
   short Seats;


};

#endif