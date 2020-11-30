#ifndef CTutor_H
#define CTutor_H
#include "CStudent.hpp"
#include "CTeacher.hpp"


class CTutor : public CStudent , public CTeacher
{
public:
  CTutor() = default;
  void load(std::ifstream &File, CBookings &subj); 
  void print(); 
  unsigned int getMatrNr(){return MatriculationNr;}
  virtual unsigned int getPersonalNr(){return PersonalNr;}
  ~CTutor()
  {}

private:
 unsigned NrOfTermsAsTutor;
};

#endif
