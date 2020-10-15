#include "caddress.hpp"
#include "cperson.hpp"
using namespace std;


void CAddress::print() const
{ 
   cout<< Street << " " << HouseNr << endl;
   cout<< Zipcode << " " << City << endl;
}
