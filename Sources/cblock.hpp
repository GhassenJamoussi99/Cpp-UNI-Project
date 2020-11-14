#ifndef CBLOCK_H
#define CBLOCK_H
#include "ctime.hpp"
#include <iostream>
#include <fstream>

class CBlock
{
 public:
   CBlock() = default;
   CBlock(short m_BlockNr,CTime m_Begin);
   short getBlockNr();
   void print();
   friend class CEvent;
   void load(std::ifstream& File);
   CTime getEnd();
   
   ~CBlock(){};

 private:
   short BlockNr;
   CTime Begin;


};

#endif