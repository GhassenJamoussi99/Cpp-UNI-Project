#ifndef CBOOKINGS_H
#define CBOOKINGS_H

#include "CSubject.hpp"
#include "CPerson.hpp"
#include "CRoom.hpp"
#include "CBlock.hpp"
#include "CTeacher.hpp"

class CStudent;
class CBooking;

class CBookings 
{
 public:
  CBookings() = default;
  CBookings(std::string str);
  void findRoom();
  unsigned int findMatrNr(std::string m_Name);

  CStudy* findStudy(std::string m_Name);
  CPerson* findTeacher(std::string m_Name);
  CRoom* findRoom(std::string m_Name);
  CBlock* findBlock(short blockNr);
  CSubject* findSubject(std::string m_Name);
  CStudent* findStudent(std::string m_Name);
  
  //void findStudent(std::string m_Name);
  unsigned findID(std::string m_Name);
  unsigned findSubjNr(std::string m_Name);
  CDate findBirthday(std::string m_Name);
  //std::string findStudy(std::string m_Name);
  void ClrMemory();
  void print();  
  ~CBookings()
  {
      ClrMemory();
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