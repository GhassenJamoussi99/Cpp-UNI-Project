#include "cblock.hpp"
#include <iomanip>

using namespace std;

CBlock::CBlock(short m_BlockNr, CTime m_Begin)
{
  BlockNr = m_BlockNr;
  Begin.Hour = m_Begin.Hour;
  Begin.Minute = m_Begin.Minute;
}

short CBlock::getBlockNr()
{
  return BlockNr;
}

void CBlock::getEnd()
{
  int STD = (Begin.Minute + 30) / 60;
  Begin.Minute = (Begin.Minute + 30) % 60;
  Begin.Hour = Begin.Hour + 1 + STD;
}

void CBlock::print() 
{ 
    cout << Begin.Hour << ":" << Begin.Minute <<" - ";
  //cout << setfill('0') << setw(2) << Begin.Hour << ":" << setw(2) << Begin.Minute << " – ";
  
  getEnd();

    cout << Begin.Hour << ":" << Begin.Minute ;

  // cout << setfill('0') << setw(2) << Begin.Hour << ":" << setw(2) << Begin.Minute << endl;
}