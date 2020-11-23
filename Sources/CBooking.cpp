#include "CBooking.hpp"
#include <regex>
using namespace std;
#include "CBookings.hpp"
unsigned CBooking::BookingNr = 0;

CBooking::CBooking(CSubject *m_Subject, CStudent *m_Student, int m_Day, int m_Month, int m_Year,
                   int m_Hour, int m_Minute, int m_Second) : Subject(m_Subject), Student(m_Student),
                                                             BookingDate(m_Day, m_Month, m_Year), BookingTime(m_Hour, m_Minute, m_Second)
{}

void CBooking::print()
{
    BookingNr++;

    cout << "Belegung Nr.  " << BookingNr << ":" << endl;

    cout << "Am ";
    BookingDate.print();
    cout << " um ";
    BookingTime.print();
    cout << endl;

    cout << "hat " << Student->getName() << "(* ";
    (Student->getBirthday()).print();
    cout << "; "
         << "MatrNr. " << Student->getMatrNr() << "; " << Student->ID << ")" << endl;
    
    cout << "das Fach '" << Subject->getSubject() << " (" << Subject->getSubjNr() << "; ";
    cout<< Subject->Study->getStudy();
    cout << ")' "
         << "belegt.";
}

void CBooking::load(ifstream &File)
{
    string Zeile;
    int Len;
    while (getline(File, Zeile))
    {
        Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

        if (Zeile == "</booking>")
        {
            break;
        }

        if (strncmp(Zeile.c_str(), "<subject>", 9) == 0)
        {
            Len = Zeile.length() - (9 + 10);
            if (strncmp(Zeile.c_str() + 9 + Len, "</subject>", 10) == 0)
            {
                Subject->Name = Zeile.substr(9, Len);
            }
        }

        if (strncmp(Zeile.c_str(), "<student>", 9) == 0)
        {

            Len = Zeile.length() - (9 + 10);
            if (strncmp(Zeile.c_str() + 9 + Len, "</student>", 10) == 0)
            {
                Student->Name = Zeile.substr(9, Len);
            }
        }
    
        if (strncmp(Zeile.c_str(), "<bookingdate>", 13) == 0)
        {
            while (getline(File, Zeile))
            {
                Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

                if (Zeile == "</bookingdate>")
                {
                    break;
                }

                if (strncmp(Zeile.c_str(), "<day>", 5) == 0)
                {
                    Len = Zeile.length() - (5 + 6);
                    if (strncmp(Zeile.c_str() + 5 + Len, "</day>", 6) == 0)
                    {
                        BookingDate.Day = stoi(Zeile.substr(5, Len));
                    }
                }

                if (strncmp(Zeile.c_str(), "<month>", 7) == 0)
                {
                    Len = Zeile.length() - (7 + 8);
                    if (strncmp(Zeile.c_str() + 7 + Len, "</month>", 8) == 0)
                    {
                        BookingDate.Month = stoi(Zeile.substr(7, Len));
                    }
                }

                if (strncmp(Zeile.c_str(), "<year>", 6) == 0)
                {
                    Len = Zeile.length() - (6 + 7);
                    if (strncmp(Zeile.c_str() + 6 + Len, "</year>", 7) == 0)
                    {
                        BookingDate.Year = stoi(Zeile.substr(6, Len));
                    }
                }
            }
        }

        if (strncmp(Zeile.c_str(), "<bookingtime>", 13) == 0)
        {
            while (getline(File, Zeile))
            {
                Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

                if (Zeile == "</bookingtime>")
                {
                    break;
                }

                if (strncmp(Zeile.c_str(), "<hour>", 6) == 0)
                {
                    Len = Zeile.length() - (6 + 7);
                    if (strncmp(Zeile.c_str() + 6 + Len, "</hour>", 7) == 0)
                    {
                        BookingTime.Hour = stoi(Zeile.substr(6, Len));
                    }
                }

                if (strncmp(Zeile.c_str(), "<minute>", 8) == 0)
                {
                    Len = Zeile.length() - (8 + 9);
                    if (strncmp(Zeile.c_str() + 8 + Len, "</minute>", 7) == 0)
                    {
                        BookingTime.Minute = stoi(Zeile.substr(8, Len));
                    }
                }

                if (strncmp(Zeile.c_str(), "<second>", 8) == 0)
                {
                    Len = Zeile.length() - (8 + 9);
                    if (strncmp(Zeile.c_str() + 8 + Len, "</second>", 9) == 0)
                    {
                        BookingTime.Second = stoi(Zeile.substr(8, Len));
                    }
                }
            }
        }
    }
}