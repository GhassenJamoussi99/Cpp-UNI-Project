#include <iostream>

using namespace std;

#include "cdate.hpp"
#include "ctime.hpp"

int main()
{
   CDate D1, D2(3, 10, 2020);
   CTime T1, T2(14, 15), T3(6, 17, 43);

   cout << "\nKlasse CDate:" << endl;
   cout << "Standardkonstruktor Heutiges Datum D1:        ";   D1.print();   cout << endl;
   cout << "Konstruktor         Tag der dt. Einheit (D2): ";   D2.print();   cout << endl;

   cout << "\nKlasse CTime:" << endl;
   cout << "Standardkonstruktor Aktuelle Uhrzeit T1:      ";   T1.print();   cout << endl;
   cout << "Konstruktor         Beginn der SU (T2):       ";   T2.print();   cout << endl;
   cout << "Konstruktor         Zeit zum Aufstehen (T3):  ";   T3.print();   cout << endl;
 
   return 0;
}
