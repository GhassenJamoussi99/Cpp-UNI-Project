#include "CSubject.hpp"

using namespace std;

CSubject::CSubject(string m_Name,unsigned m_SubjNr,CStudy *m_Study)
: Name(m_Name), SubjNr(m_SubjNr),Study(m_Study)
{}

//Static SubjNr

void CSubject::addEvent(CEvent *m_Event)
{
    Events.push_back(m_Event);
}

