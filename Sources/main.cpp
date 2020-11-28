#include <iostream>
using namespace std;

#include "CBookings.hpp"

int main()
{
   CBookings Belegungen("belegungen.xml");

   Belegungen.printBelegungen();

    return 0;
}
