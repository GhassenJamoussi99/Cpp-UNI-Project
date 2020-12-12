#include "CSubject.hpp"
#include <regex>
#include "CBookings.hpp"

using namespace std;


CSubject::CSubject(string m_Name, unsigned m_SubjNr, CStudy *m_Study)
    : SubjNr(m_SubjNr), Name(m_Name), Study(m_Study)
{
}

void CSubject::addEvent(CEvent *m_Event)
{
    Events.push_back(m_Event);
}


void CSubject::load(ifstream &File, CBookings &subj)
{
    string Zeile;
    int Len;
    while (getline(File, Zeile))
    {
        Zeile = regex_replace(Zeile, regex("^ +"), ""); //nur führende Leerzeichen entfernen

        if (Zeile == "</subject>")
        {
            break;
        }

        if (strncmp(Zeile.c_str(), "<name>", 6) == 0)
        {
            Len = Zeile.length() - (6 + 7); // length von "<name>" und </name> -> 6 + 7
            if (strncmp(Zeile.c_str() + 6 + Len, "</name>", 7) == 0)
            {
                Name = Zeile.substr(6, Len);
            }
        }

        if (strncmp(Zeile.c_str(), "<subjectnr>", 11) == 0)
        {
            Len = Zeile.length() - (11 + 12);
            if (strncmp(Zeile.c_str() + 11 + Len, "</subjectnr>", 12) == 0)
            {
                SubjNr = stoi(Zeile.substr(11, Len));
            }
        }
        if (strncmp(Zeile.c_str(), "<event>", 11) == 0)
        {
            CEvent *E = new CEvent();
            E->loadEvent(File, subj);
            Events.push_back(E);     
        }
        
        if (strncmp(Zeile.c_str(), "<study>", 7) == 0)
        {
            Len = Zeile.length() - (7 + 8);
            if (strncmp(Zeile.c_str() + 7 + Len, "</study>", 8) == 0)
            {
                 Study = subj.findStudy(Zeile.substr(7, Len));

            }
        }
        
    }


}