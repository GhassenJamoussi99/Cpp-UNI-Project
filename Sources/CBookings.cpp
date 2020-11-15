#include "CBookings.hpp"
#include <fstream>
using namespace std;
#include <regex>

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
        S1->load(src);
        Persons.push_back(S1);
      }

      if (Zeile.compare("<teacher>") == 0)
      {
        CTeacher *T1 = new CTeacher();
        T1->load(src);
        Persons.push_back(T1);
      }

      if (Zeile.compare("<subject>") == 0)
      {
        CSubject *S = new CSubject();
        S->load(src);
        Subjects.push_back(S);
      }
      
      if (Zeile.compare("<booking>") == 0)
      {
        CBooking *CB = new CBooking();
        CB->load(src);
        Bookings.push_back(CB);
      }
    }
  }
}

void CBookings::print()
{
  cout << "Datei wurde erfolgreich eingelesen!" << endl;

  for (int i = 0; i < Bookings.size(); i++)
  {  
      cout << "BookingNr " << i+1;  
      cout << "Subject "  << Bookings[i]->Subject->Name << endl;
      cout << "Student's name " << Bookings[i]->Student->getName();
      cout << endl;
      cout <<" BookingDate : ";
      Bookings[i]->BookingDate.print();
      cout << endl;
      cout << " BookingTime " ;
      Bookings[i]->BookingTime.print();
      cout << endl;
    
  }
}
