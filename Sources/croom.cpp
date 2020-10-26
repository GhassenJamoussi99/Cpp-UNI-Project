#include "CRoom.hpp"

using namespace std;

CRoom::CRoom(string m_Name, string m_Building , short m_Seats ):
Name(m_Name),Building(m_Building),Seats(m_Seats)
{}

void CRoom::print() const
{
  cout << "Raum " << Name << " (" << Building << ")" ;
}
