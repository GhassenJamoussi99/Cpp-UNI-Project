#include "CBlock.hpp"
#include <iomanip>

using namespace std;

CBlock::CBlock(short m_BlockNr, CTime m_Begin):
BlockNr(m_BlockNr),Begin(m_Begin.Hour,m_Begin.Minute)
{}

short CBlock::getBlockNr()
{
  return BlockNr;
}

CTime CBlock::getEnd()
{
  int STD = (Begin.Minute + 30) / 60;
  Begin.Minute = (Begin.Minute + 30) % 60;
  Begin.Hour = Begin.Hour + 1 + STD;

  return Begin;
}

void CBlock::print()
{
  int HBegin = Begin.Hour;
  int MBegin = Begin.Minute;

  cout << setfill('0') << setw(2) << Begin.Hour << ":" << setw(2) << Begin.Minute << " - ";

  getEnd();

  cout << setfill('0') << setw(2) << Begin.Hour << ":" << setw(2) << Begin.Minute;

  Begin.Hour = HBegin;
  Begin.Minute = MBegin;
}