#include "CBookings.hpp"
#include <fstream>
using namespace std;


CBookings::CBookings(string str)
{
   ifstream src(str);
   string line;

   if (!src)
   {
     cout << str << " konnte nicht geoffnet werden !" << endl;
     exit(1);
   }

   while(getline(src,line))
   {

       
   }




    
}
