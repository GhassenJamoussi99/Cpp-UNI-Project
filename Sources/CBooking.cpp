#include "CBooking.hpp"

using namespace std;

CBooking::CBooking(CSubject *m_Subject, CStudent *m_Student, int m_Day, int m_Month, int m_Year,
                   int m_Hour, int m_Minute, int m_Second) : Subject(m_Subject), Student(m_Student),
                                                             BookingDate(m_Day, m_Month, m_Year), BookingTime(m_Hour, m_Minute, m_Second)
{
    BookingNr++;
}

void CBooking::print()
{
    cout << "Belegung Nr.    " << BookingNr << ":" << endl;

    cout << "Am";
    BookingDate.print();
    cout << " um ";
    BookingTime.print();
    cout << endl;

    cout<<"hat " << Student->getName() << "(* ";
    (Student->getBirthday()).print();
    cout<<"; " <<"MatrNr. "<< Student->getMatrNr() <<")" << endl;
    
    cout<<"das Fach " //STOPPED HERE 


}