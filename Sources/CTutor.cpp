#include "CTutor.hpp"
//TODO

void CTutor::print()
{
     if (PersonalNr  == 0)
    {
        CStudent::print();
    }
    else
    {
        CTeacher::print();
    }
    
}