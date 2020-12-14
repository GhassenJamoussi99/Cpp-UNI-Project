#include <fstream>
#include <regex>
#include "CStudent.hpp"
#include "CBooking.hpp"
#include "CBookings.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

CBookings::CBookings(string str)
{
  ifstream src(str);
  string Zeile;

  if (!src)
  {
    cout << str << " konnte nicht geoffnet werden !" << endl;
    exit(1);
  }
  else
  {
    while (getline(src, Zeile))
    {
      Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

      if (Zeile == "</date>")
      {
        break;
      }

      if (Zeile.compare("<room>") == 0)
      {
        CRoom *R = new CRoom();
        R->load(src);
        Rooms.push_back(R);
      }
      if (Zeile.compare("<block>") == 0)
      {
        CBlock *B = new CBlock();
        B->load(src);
        Blocks.push_back(B);
      }
      if (Zeile.compare("<study>") == 0)
      {
        CStudy *S = new CStudy();
        S->load(src);
        Studies.push_back(S);
      }

      if (Zeile.compare("<student>") == 0)
      {
        CStudent *S1 = new CStudent();
        S1->load(src, *this);
        Persons.push_back(S1);
      }

      if (Zeile.compare("<teacher>") == 0)
      {
        CTeacher *T1 = new CTeacher();
        T1->load(src);
        Persons.push_back(T1);
      }

      if (Zeile.compare("<tutor>") == 0)
      {
        CTutor *TU = new CTutor();
        TU->load(src, *this);
        Persons.push_back(TU);
      }

      if (Zeile.compare("<subject>") == 0)
      {
        CSubject *S = new CSubject();
        S->load(src, *this);
        Subjects.push_back(S);
      }

      if (Zeile.compare("<booking>") == 0)
      {
        CBooking *CB = new CBooking();
        CB->load(src, *this);
        Bookings.push_back(CB);
      }
    }
  }
}

CStudy *CBookings::findStudy(string m_Name)
{
  for (int i = 0; i < Studies.size(); i++)
  {
    if (Studies[i]->getStudy() == m_Name)
    {
      return Studies[i];
    }
  }
  return NULL;
}

void CBookings::operator()(Data D)
{
  switch (D)
  {
  case ofPersons:
  {
    printPersons();
    break;
  }
  case ofStudents:
  {
    printStudents();
    break;
  }
  case ofTeachers:
  {
    printTeachers();
    break;
  }
  case ofBookings:
  {
    printBookings();
    break;
  }
  case ofScheduleOfStudents:
  {
    printSchedOfStudents();
    break;
  }
  case ofScheduleOfStudies:
  {
    printSchedOfStudies();
    break;
  }
  default:
    break;
  }
}

CPerson *CBookings::findTeacher(string m_Name)
{
  for (int i = 0; i < Persons.size(); i++)
  {
    if (Persons[i]->getName() == m_Name)
    {
      return Persons[i];
    }
  }
  return NULL;
}

CRoom *CBookings::findRoom(string m_Name)
{
  for (int i = 0; i < Rooms.size(); i++)
  {
    if (Rooms[i]->getName() == m_Name)
    {
      return Rooms[i];
    }
  }
  return NULL;
}

CBlock *CBookings::findBlock(short blockNr)
{
  for (int i = 0; i < Blocks.size(); i++)
  {
    if (Blocks[i]->getBlockNr() == blockNr)
    {
      return Blocks[i];
    }
  }
  return NULL;
}

CSubject *CBookings::findSubject(std::string m_Name)
{
  for (int i = 0; i < Subjects.size(); i++)
  {
    if (Subjects[i]->getSubject() == m_Name)
    {
      return Subjects[i];
    }
  }
  return NULL;
}

CStudent *CBookings::findStudent(std::string m_Name)
{
  for (int i = 0; i < Persons.size(); i++)
  {
    CStudent *Student = dynamic_cast<CStudent *>(Persons[i]);
    if (Student)
    {
      if (Student->getName() == m_Name)
      {
        return Student;
      }
    }
  }
  return NULL;
}

void CBookings::printPersons()
{
  cout << "Datei wurde erfolgreich eingelesen!\n"
       << endl;
  cout << "Personen : " << endl;

  for (int i = 0; i < Persons.size(); i++)
  {
    Persons[i]->print();
  }

  cout << endl;
}

void CBookings::printStudents()
{
  cout << "Studenten: " << endl;

  for (int i = 0; i < Persons.size(); i++)
  {
    CStudent *Student = dynamic_cast<CStudent *>(Persons[i]);
    if (Student)
      Persons[i]->print();
  }

  cout << endl;
}

void CBookings::printTeachers()
{
  cout << "Dozenten: " << endl;

  for (int i = 0; i < Persons.size(); i++)
  {
    CTeacher *Dozent = dynamic_cast<CTeacher *>(Persons[i]);
    if (Dozent)
      Persons[i]->print();
  }

  cout << endl;
}

void CBookings::Stundenplan(CStudent *std)
{
  cout << endl;
  cout << "|-----|------------------|------------------|------------------|------------------|------------------|" << endl;
  cout << "|     |        Mo        |        Di        |        Mi        |        Do        |        Fr        |" << endl;
  cout << "|-----|------------------|------------------|------------------|------------------|------------------|" << endl;

  vector<vector<string>> Fach;
  vector<vector<string>> Dozent;
  vector<vector<string>> Raum;

  int count = 0;

  for (int i = 0; i < 7; i++)
  {
    vector<string> temp;
    for (int j = 0; j < 5; j++)
    {
      temp.push_back("");
    }
    Fach.push_back(temp);
    Dozent.push_back(temp);
    Raum.push_back(temp);
  }

  for (int i = 0; i < Bookings.size(); i++)
  {
    if (Bookings[i]->Student->getName() == std->getName())
    {
      int a = (Bookings[i]->Subject->Events).size();
      for (int j = 0; j < a; j++)
      {
        Fach[Bookings[i]->Subject->Events[j]->getBlock() - 1][Bookings[i]->Subject->Events[j]->getWeekDay()] = Bookings[i]->Subject->Events[j]->getName();
        Dozent[Bookings[i]->Subject->Events[j]->getBlock() - 1][Bookings[i]->Subject->Events[j]->getWeekDay()] = Bookings[i]->Subject->Events[j]->getDozentName();
        Raum[Bookings[i]->Subject->Events[j]->getBlock() - 1][Bookings[i]->Subject->Events[j]->getWeekDay()] = Bookings[i]->Subject->Events[j]->getRoom();
      }
    }
  }

  for (int i = 0; i < Fach.size(); i++)
  {
    for (int j = 0; j < Fach[i].size(); j++)
    {
      if (j == 0)
      {
        cout << "|     |";
      }
      cout << Fach[i][j] << setfill(' ') << setw(19 - Fach[i][j].length()) << "|";
    }
    cout << "\n";
    for (int j = 0; j < Dozent[i].size(); j++)
    {

      if (j == 0)
      {
        count++;
        cout << "|  " << count << "  |";
      }
      cout << Dozent[i][j] << setfill(' ') << setw(19 - Dozent[i][j].length()) << "|";
    }
    cout << "\n";
    for (int j = 0; j < Raum[i].size(); j++)
    {
      if (j == 0)
      {
        cout << "|     |";
      }
      cout << Raum[i][j] << setfill(' ') << setw(19 - Raum[i][j].length()) << "|";
    }
    cout << "\n|-----|------------------|------------------|------------------|------------------|------------------|" << endl;
  }

  cout << endl;
}

void CBookings::StundenplanStd(CStudy *study)
{
  cout << endl;
  cout << "|-----|------------------|------------------|------------------|------------------|------------------|" << endl;
  cout << "|     |        Mo        |        Di        |        Mi        |        Do        |        Fr        |" << endl;
  cout << "|-----|------------------|------------------|------------------|------------------|------------------|" << endl;

  string StudyName = study->getStudy();

  vector<vector<string>> Fach;
  vector<vector<string>> Dozent;
  vector<vector<string>> Raum;

  int count = 0;

  for (int i = 0; i < 7; i++)
  {
    vector<string> temp;
    for (int j = 0; j < 5; j++)
    {
      temp.push_back("");
    }
    Fach.push_back(temp);
    Dozent.push_back(temp);
    Raum.push_back(temp);
  }

  for (int i = 0; i < Subjects.size(); i++)
  {
    if (Subjects[i]->getStudyName() == StudyName)
    {
      int a = (Subjects[i]->Events).size();

      for (int j = 0; j < a; j++)
      {
        //cout << Subjects[i]->Events[j]->getBlock() - 1 << Subjects[i]->Events[j]->getWeekDay() << endl;
        Fach[Subjects[i]->Events[j]->getBlock() - 1][Subjects[i]->Events[j]->getWeekDay()] = Subjects[i]->Events[j]->getName();
        Dozent[Subjects[i]->Events[j]->getBlock() - 1][Subjects[i]->Events[j]->getWeekDay()] = Subjects[i]->Events[j]->getDozentName();
        Raum[Subjects[i]->Events[j]->getBlock() - 1][Subjects[i]->Events[j]->getWeekDay()] = Subjects[i]->Events[j]->getRoom();
      }
    }
  }

  for (int i = 0; i < Fach.size(); i++)
  {
    for (int j = 0; j < Fach[i].size(); j++)
    {
      if (j == 0)
      {
        cout << "|     |";
      }
      cout << Fach[i][j] << setfill(' ') << setw(19 - Fach[i][j].length()) << "|";
    }
    cout << "\n";
    for (int j = 0; j < Dozent[i].size(); j++)
    {

      if (j == 0)
      {
        count++;
        cout << "|  " << count << "  |";
      }
      cout << Dozent[i][j] << setfill(' ') << setw(19 - Dozent[i][j].length()) << "|";
    }
    cout << "\n";
    for (int j = 0; j < Raum[i].size(); j++)
    {
      if (j == 0)
      {
        cout << "|     |";
      }
      cout << Raum[i][j] << setfill(' ') << setw(19 - Raum[i][j].length()) << "|";
    }
    cout << "\n|-----|------------------|------------------|------------------|------------------|------------------|" << endl;
  }

  cout << endl;
}

void CBookings::printSchedOfStudents()
{
  cout << "Stundenplaene der Studenten:\n"
       << endl;
  for (int i = 0; i < Persons.size(); i++)
  {
    CStudent *Student = dynamic_cast<CStudent *>(Persons[i]);
    if (Student)
    {
      cout << "Stundenplan fuer " << Student->getName() << ": \n";

      Stundenplan(Student);
    }
  }
}

void CBookings::printSchedOfStudies()
{
  cout << "Stundenplaene der Studiengaenge:\n"
       << endl;

  for (int i = 0; i < Studies.size(); i++)
  {
    cout << "Stundenplan fuer " << Studies[i]->getStudy() << ": \n";
    StundenplanStd(Studies[i]);
  }
}

void CBookings::printBookings()
{

  for (int i = 0; i < Bookings.size(); i++)
  {
    Bookings[i]->print();
    cout << endl;
    cout << endl;
  }
}

void CBookings::ClrMemory()
{
  cout << "Bloecke freigeben ..." << endl;
  for (int i = 0; i < Blocks.size(); i++)
  {
    delete Blocks[i];
  }
  cout << "Bloecke freigeben ok" << endl;

  cout << "Raeume freigeben ..." << endl;
  for (int i = 0; i < Blocks.size(); i++)
  {
    delete Rooms[i];
  }
  cout << "Raeume freigeben ok" << endl;

  cout << "Studiengaenge freigeben ..." << endl;
  for (int i = 0; i < Studies.size(); i++)
  {
    delete Studies[i];
  }
  cout << "Studiengaenge freigeben ok" << endl;

  cout << "Personen freigeben ..." << endl;
  for (int i = 0; i < Persons.size(); i++)
  {
    delete Persons[i];
  }
  cout << "Personen freigeben ok" << endl;

  cout << "Faecher freigeben ..." << endl;
  for (int i = 0; i < Subjects.size(); i++)
  {
    delete Subjects[i];
  }
  cout << "Faecher freigeben ok" << endl;

  cout << "Belegungen freigeben ..." << endl;
  for (int i = 0; i < Bookings.size(); i++)
  {
    delete Bookings[i];
  }
  cout << "Belegungen freigeben ok" << endl;
}