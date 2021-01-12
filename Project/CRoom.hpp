#ifndef CROOM_H
#define CROOM_H

#include <string>
#include <iostream>
#include <fstream>

class CRoom
{
  public:
   CRoom() = default;
   CRoom(std::string m_Name, std::string m_Building , short m_Seats );
   std::string getName() {return Name;}
   void setName(std::string m_Name){ Name = m_Name;}
   void print() const;
   void load(std::ifstream& File);
   ~CRoom()
   {
            std::cout << "   Raum Nr. " << Name << " wird vernichtet."<<std::endl;

   }


  private:
   std::string Name; 
   std::string Building;
   short Seats;


};

#endif