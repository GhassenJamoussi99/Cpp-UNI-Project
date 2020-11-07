#include "CStudy.hpp"

using namespace std;

CStudy::CStudy(string m_Name, bool m_NC, short m_NrOfTerms) 
:Name(m_Name), NC(m_NC), NrOfTerms(m_NrOfTerms)
{}



void CStudy::print() const
{
   cout<<Name;
}