#ifndef CBOOKINGS_H
#define CBOOKINGS_H

#include "CSubject.hpp"
#include "CPerson.hpp"
#include "CRoom.hpp"
#include "CBlock.hpp"
#include "CTeacher.hpp"
#include "CTutor.hpp"
#include "CSchedule.hpp"

enum Data
{
  ofPersons,
  ofStudents,
  ofTeachers,
  ofBookings,
  ofScheduleOfStudents,
  ofScheduleOfStudies
};

class CStudent;
class CBooking;

class CBookings
{
public:
  CBookings() = default;
  CBookings(std::string str);
  void operator()(Data D);
  void findRoom();
  unsigned int findMatrNr(std::string m_Name);

  CStudy *findStudy(std::string m_Name);
  CPerson *findTeacher(std::string m_Name);
  CRoom *findRoom(std::string m_Name);
  CBlock *findBlock(short blockNr);
  CSubject *findSubject(std::string m_Name);
  CStudent *findStudent(std::string m_Name);
  //Noch eine Funktion für den Ausgabeoperator

  void ClrMemory();
  void printBookings();
  void printPersons();
  void printStudents();
  void printTeachers();
  void Stundenplan(CStudent *std);
  void Stundenplan(CSubject *sbj);
  //void Stundenplan(CStudent std);
  void printSchedOfStudents();
  void printSchedOfStudies();

  ~CBookings()
  {
    ClrMemory();
  }

private:
  std::vector<CBlock *> Blocks;
  std::vector<CRoom *> Rooms;
  std::vector<CStudy *> Studies;
  std::vector<CPerson *> Persons;
  std::vector<CSubject *> Subjects;
  std::vector<CBooking *> Bookings;
  CSchedule *Schedule;
};

#endif
