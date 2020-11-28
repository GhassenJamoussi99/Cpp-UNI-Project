#ifndef CTutor_H
#define CTutor_H
#include "CStudent.hpp"
#include "CTeacher.hpp"

class CTutor : public CStudent , public CTeacher
{
public:
  CTutor() = default;
  void print(CPerson &subj); //Mischung aus den print-Methoden 
                //von Student und Dozent: 
                //Name (* Geburtstag; ID; Matrikelnr.;Personalnr.)
  unsigned int getMatrNr(){return 0;}
  ~CTutor()
  {}

private:
 unsigned NrOfTermsAsTutor;
};

#endif
