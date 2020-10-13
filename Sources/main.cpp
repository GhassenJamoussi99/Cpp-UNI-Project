#include <iostream>

using namespace std;

#include "cdate.hpp"
#include "ctime.hpp"
#include "cblock.hpp"
#include "croom.hpp"
#include "caddress.hpp"
#include "cperson.hpp"

int main()
{
   int i;

   // Uhrzeiten
   CTime Zeit0800( 8,  0);
   CTime Zeit1000(10,  0);
   CTime Zeit1215(12, 15);
   CTime Zeit1415(14, 15);
   CTime Zeit1600(16,  0);
   CTime Zeit1745(17, 45);
   CTime Zeit1930(19, 30);

   // Bloecke
   CBlock Block1( 1, Zeit0800);
  /* CBlock Block2( 2, Zeit1000);
   CBlock Block3( 3, Zeit1215);
   CBlock Block4( 4, Zeit1415);
   CBlock Block5( 5, Zeit1600);
   CBlock Block6( 6, Zeit1745);
   CBlock Block7( 7, Zeit1930);
   CBlock *Bloecke[7] = { &Block1, &Block2, &Block3, &Block4, &Block5, &Block6, &Block7 };

   // Raeume
   CRoom D114("D 114", "Haus Bauswesen", 28);
   CRoom D117("H3 (D 117)", "Haus Bauwesen", 104);
   CRoom D419("D 419", "Haus Bauswesen", 40);
   CRoom *Raeume[3] = { &D114, &D117, &D419 };

   // Personen
   CPerson Student1("Anna Albrecht", "Albrechtstr.", "15a", 12045, "Berlin", 15, 9, 1989);
   CPerson Student2("Detlef Dicht", "Dichterweg", "27", 29031, "Vordertupfingen", 27, 5, 1991);
   CPerson Student3("Frank Faust", "Goethestr.", "3-5", 12345, "Berlin", 3, 11, 1987);
   CPerson Student4("Max Muster", "Meistergasse", "23", 19885, "Hintertupfingen", 19, 7, 1985);
   CPerson *Studenten[4] = { &Student1, &Student2, &Student3, &Student4 };
   CAddress *Adressen[4] = { &(Student1.getAddress()), &(Student2.getAddress()),
                             &(Student3.getAddress()), &(Student4.getAddress()) };

   cout << "\nKlasse CBlock:" << endl;
   for (i = 0; i < 7; i++)
   {
      cout << "Block Nr. " << Bloecke[i]->getBlockNr() << " (";
      Bloecke[i]->print();
      cout << ")" << endl;
   }

   cout << "\nKlasse CRoom:" << endl;
   for (i = 0; i < 3; i++)
   {
      Raeume[i]->print();
      cout << endl;
   }

   cout << "\nKlasse CAddress:" << endl;
   for (i = 0; i < 4; i++)
   {
      Adressen[i]->print();
      cout << endl;
   }

   cout << "\nKlasse CPerson:" << endl;
   for (i = 0; i < 4; i++)
   {
      Studenten[i]->print();
      cout << endl;
   }
*/
   return 0;
}
