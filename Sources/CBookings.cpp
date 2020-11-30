#include "CBookings.hpp"
#include <fstream>
using namespace std;
#include <regex>
#include "CStudent.hpp"
#include "CBooking.hpp"

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

void CBookings::printPersonen()
{
  cout << "Datei wurde erfolgreich eingelesen!\n" << endl;
  cout << "Personen : " << endl;

  for (int i = 0; i < Persons.size(); i++)
  {
    Persons[i]->print(); 
  }

  cout << endl;
}

void CBookings::printBelegungen()
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

  cout << "Studenten freigeben ..." << endl;
  for (int i = 0; i < Persons.size(); i++)
  {
    CStudent *Student = dynamic_cast<CStudent *>(Persons[i]);
    if (Student)
    {
      Persons.erase(Persons.begin() + i);
      delete Student;
      i--;
    }
  }
  cout << "Studenten freigeben ok" << endl;

  cout << "Dozenten freigeben ..." << endl;
  for (int i = 0; i < Persons.size(); i++)
  {
    CTeacher *Teacher = dynamic_cast<CTeacher *>(Persons[i]);
    if (Teacher)
    {
      delete Teacher;
    }
  }
  cout << "Dozenten freigeben ok" << endl;

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