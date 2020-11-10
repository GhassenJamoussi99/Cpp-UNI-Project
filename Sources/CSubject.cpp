#include "CSubject.hpp"

using namespace std;

CSubject::CSubject(string m_Name,unsigned m_SubjNr,CStudy *m_Study)
: SubjNr(m_SubjNr), Name(m_Name), Study(m_Study)
{}

void CSubject::addEvent(CEvent *m_Event)
{
    Events.push_back(m_Event);
}

