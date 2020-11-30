#ifndef CTutor_H
#define CTutor_H
#include "CStudent.hpp"
#include "CTeacher.hpp"


class CTutor : public CStudent , public CTeacher
{
public:
  CTutor() = default;
  void load(std::ifstream &File, CBookings &subj); //Work on the load function
  void print(); //Mischung aus den print-Methoden 
                //von Student und Dozent: 
                //Name (* Geburtstag; ID; Matrikelnr.;Personalnr.)
  unsigned int getMatrNr(){return MatriculationNr;}
  virtual unsigned int getPersonalNr(){return PersonalNr;}
  ~CTutor()
  {}

private:
 unsigned NrOfTermsAsTutor;
};

#endif
