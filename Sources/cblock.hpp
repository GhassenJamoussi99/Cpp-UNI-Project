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
   short getBlockNr(){return BlockNr;}
   void print();
   friend class CEvent;
   void load(std::ifstream& File);
   CTime getEnd();
   
   ~CBlock()
   {
      std::cout << "   Block Nr. " << BlockNr << " (";
      CBlock::print();
      std::cout << ") wird vernichtet."<<std::endl;
   }

 private:
   short BlockNr;
   CTime Begin;


};

#endif