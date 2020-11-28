#ifndef CTEACHER_H
#define CTEACHER_H
#include "CPerson.hpp"
#include <fstream>

class CTeacher : virtual public CPerson  //Auf virtual public setzen, um Diamond of Death zu vermeiden
{
public:
        CTeacher() = default;
        CTeacher(std::string m_Name, std::string m_Street,
                 std::string m_HouseNr, unsigned m_Zipcode,
                 std::string m_City, int m_Day, int m_Month, int m_Year,
                 int m_PersonalNr);
        unsigned int getPersonalNr() {return PersonalNr;}
        unsigned int getMatrNr() { return 0;}
        virtual void print();  //..
        void load(std::ifstream &File);
        ~CTeacher()
        {
            std::cout << "   Lehrer*in " << Name << " wird vernichtet." << std::endl;
        }

protected:
        unsigned PersonalNr = 0;
};

#endif