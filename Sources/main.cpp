#include <iostream>
#include <vector>
using namespace std;

#include "CTime.hpp"
#include "CBlock.hpp"
#include "CRoom.hpp"
#include "CPerson.hpp"
#include "CStudent.hpp"
#include "CTeacher.hpp"
#include "CEvent.hpp"
#include "CStudy.hpp"
#include "CSubject.hpp"
#include "CBooking.hpp"

int main()
{
   // Uhrzeiten
   CTime Zeit0800(8, 0);
   CTime Zeit1000(10, 0);
   CTime Zeit1215(12, 15);
   CTime Zeit1415(14, 15);
   CTime Zeit1600(16, 0);
   CTime Zeit1745(17, 45);
   CTime Zeit1930(19, 30);

   // Bloecke
   CBlock Block1(1, Zeit0800);
   CBlock Block2(2, Zeit1000);
   CBlock Block3(3, Zeit1215);
   CBlock Block4(4, Zeit1415);
   CBlock Block5(5, Zeit1600);
   CBlock Block6(6, Zeit1745);
   CBlock Block7(7, Zeit1930);

   // Raeume
   CRoom D114("D 114", "Haus Bauswesen", 28);
   CRoom D117("H3 ", "Haus Bauwesen ", 104);
   CRoom D136("H5 ", "Haus Bauwesen ", 104);
   CRoom D209("D 209", "Haus Bauwesen ", 35);
   CRoom D419("D 419", "Haus Bauswesen", 40);
   CRoom B301("B 301", "Haus Gauss ", 100);

   // Studiengaenge
   CStudy *TechInfo = new CStudy("Technische Informatik", false, 8);
   CStudy *Physik = new CStudy("Physik", true, 10);
   CStudy *ETechnik = new CStudy("Elektrotechnik", false, 8);

   // Personen
   CStudent *Student1 = new CStudent("Anna Albrecht", "Albrechtstr.", "15a", 12045, "Berlin",
                                     15, 9, 1989, 191278, 2, 28, TechInfo);
   CStudent *Student2 = new CStudent("Detlef Dicht", "Dichterweg", "27", 29031, "Vordertupfingen",
                                     27, 5, 1991, 191115, 3, 31, Physik);
   CStudent *Student3 = new CStudent("Frank Faust", "Goethestr.", "3-5", 12345, "Berlin",
                                     3, 11, 1987, 191492, 2, 24, TechInfo);
   CStudent *Student4 = new CStudent("Max Muster", "Meistergasse", "23", 19885, "Hintertupfingen",
                                     19, 7, 1985, 191368, 3, 30, ETechnik);
   CPerson *Dozent1 = new CTeacher("Kevin Kaufmann", "Kaiserstr.", "38", 12075, "Berlin",
                                   15, 6, 1959, 12);
   CPerson *Dozent2 = new CTeacher("Nathan Neuling", "Neue Str.", "7", 10777, "Berlin",
                                   9, 9, 1969, 97);
   CPerson *Dozent3 = new CTeacher("Sabine Sauber", "Saubere Gasse", "1", 17001, "Auf dem Land",
                                   3, 1, 1962, 68);
   CPerson *Dozent4 = new CTeacher("Willi Witzig", "Wunderweg", "99", 15911, "Nauen",
                                   9, 11, 1976, 34);
   // Veranstaltungen
   CEvent *Event1 = new CEvent("SU Mathe I ", Dozent2, B301, Block2, Mo, 1); //Minimal reproducible issue
   CEvent *Event2 = new CEvent("SU Digitale Systeme ", Dozent4, D136, Block5, Di, 1);
   CEvent *Event3 = new CEvent("Ueb Digitale Systeme", Dozent4, D114, Block6, Di, 1);
   CEvent *Event4 = new CEvent("Ueb Mathe I ", Dozent2, D209, Block2, Mi, 1);
   CEvent *Event5 = new CEvent("Englisch ", Dozent3, D419, Block5, Do, 1);
   CEvent *Event6 = new CEvent("SU Informatik I ", Dozent1, D117, Block2, Fr, 1);
   CEvent *Event7 = new CEvent("Ueb Informatik I ", Dozent1, D114, Block3, Fr, 2);
   CEvent *Event8 = new CEvent("Ueb Informatik I ", Dozent1, D114, Block4, Fr, 2);

   // Faecher einschl. der Zuordnung zu den Veranstaltungen
   CSubject *Fach1 = new CSubject("Mathe I", 31103, TechInfo);
   CSubject *Fach2 = new CSubject("Digitale Systeme", 33102, ETechnik);
   CSubject *Fach3 = new CSubject("Informatik I", 31101, TechInfo);
   CSubject *Fach4 = new CSubject("Englisch", 31209, TechInfo);
   CSubject *Fach5 = new CSubject("Quantenmechanik", 32502, Physik);
   Fach1->addEvent(Event1);
   Fach1->addEvent(Event4);
   Fach2->addEvent(Event2);
   Fach2->addEvent(Event3);
   Fach3->addEvent(Event6);
   Fach3->addEvent(Event7);
   Fach3->addEvent(Event8);
   Fach4->addEvent(Event5);
   // Quantenmechanik faellt dieses Semester wegen Personalmangel aus

   // Belegungen
   vector<CBooking *> Belegungen;
   Belegungen.push_back(new CBooking(Fach3, Student1, 4, 10, 2020, 5, 17, 29));
   Belegungen.push_back(new CBooking(Fach2, Student1, 4, 10, 2020, 5, 19, 43));
   Belegungen.push_back(new CBooking(Fach1, Student1, 4, 10, 2020, 5, 23, 7));
   Belegungen.push_back(new CBooking(Fach1, Student2, 4, 10, 2020, 13, 28, 56));
   Belegungen.push_back(new CBooking(Fach1, Student3, 4, 10, 2020, 17, 3, 31));
   Belegungen.push_back(new CBooking(Fach1, Student4, 5, 10, 2020, 1, 52, 11));
   int i;
   for (i = 0; i < Belegungen.size(); i++)
   {
      Belegungen[i]->print();
      cout << endl
           << endl;
   }

   cout << endl;

   // Speicherbereiche freigeben:
   for (i = 0; i < Belegungen.size(); i++)
      delete Belegungen[i];
   delete Fach1;
   delete Fach2;
   delete Fach3;
   delete Fach4;
   delete Fach5;
   delete Event1;
   delete Event2;
   delete Event3;
   delete Event4;
   delete Event5;
   delete Event6;
   delete Event7;
   delete Event8;
   delete Student1;
   delete Student2;
   delete Student3;
   delete Student4;
   delete Dozent1;
   delete Dozent2;
   delete Dozent3;
   delete Dozent4;
   delete Physik;
   delete ETechnik;
   /*delete D114;
   delete D117;
   delete D136;
   delete D209;
   delete D419;
   delete B301;
   delete Block1;
   delete Block2;
   delete Block3;
   delete Block4;
   delete Block5;
   delete Block6;
   delete Block7;
   delete Zeit0800;
   delete Zeit1000;
   delete Zeit1215;
   delete Zeit1415;
   delete Zeit1600;
   delete Zeit1745;
   delete Zeit1930;
   */
   return 0;
}
