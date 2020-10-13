#ifndef CBLOCK_H
#define CBLOCK_H
#include "ctime.hpp"
#include <iostream>

class CBlock
{
 public:
   CBlock();
   CBlock(short m_BlockNr, CTime m_Begin);

   void getBlockNr();
   void print() const;
   void getEnd();
   
   ~CBlock(){};

 private:
   short BlockNr = 1;
   CTime Begin;

};

#endif