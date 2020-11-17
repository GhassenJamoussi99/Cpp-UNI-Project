#ifndef CBOOKINGS_H
#define CBOOKINGS_H

#include "CSubject.hpp"
#include "CPerson.hpp"
#include "CRoom.hpp"
#include "CStudy.hpp"
#include "CBooking.hpp"
#include "CBlock.hpp"
#include "CTeacher.hpp"
#include "CStudent.hpp"

class CBookings
{
 public:
  CBookings() = default;
  CBookings(std::string str);
  void findRoom();
  unsigned int findMatrNr(std::string m_Name);
  unsigned findID(std::string m_Name);
  void print();  
  //More to come
  ~CBookings()
  {
      //printf shreiben 
  }
  
 private:
  std::vector<CBlock *>Blocks;
  std::vector<CRoom *>Rooms;
  std::vector<CStudy *>Studies;
  std::vector<CPerson *>Persons;
  std::vector<CSubject *>Subjects;
  std::vector<CBooking *>Bookings;   
};




#endif