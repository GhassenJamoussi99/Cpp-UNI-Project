#ifndef CBLOCK_H
#define CBLOCK_H
#include "ctime.hpp"
#include <iostream>

class CBlock
{
 public:
   CBlock() = default;
   CBlock(short m_BlockNr,CTime m_Begin);

   short getBlockNr();
   void print() ;
   void getEnd();
   
   ~CBlock(){};

 private:
   short BlockNr = 1;
   CTime Begin;


};

#endif