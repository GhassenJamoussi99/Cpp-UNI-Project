#include "caddress.hpp"

using namespace std;

void CAddress::print() const
{ 
   cout<< Street <<" " << HouseNr << endl;
   cout<< Zipcode << " " << City << endl;
}
