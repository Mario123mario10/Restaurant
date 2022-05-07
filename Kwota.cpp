
#include "Kwota.h"



Kwota::Kwota()
{
  zlote = 0;
  grosze = 0;
}

Kwota::Kwota(int zlote, int grosze)
{
  this -> zlote = zlote;
  this -> grosze = grosze;
}

// Kwota::Kwota(float kwota)
// {}

Kwota& Kwota::operator+= (const Kwota&  inna_kwota)
{
  ustaw_zlote(inna_kwota.daj_zlote() + zlote);
  ustaw_grosze(inna_kwota.daj_grosze() + grosze);
}
Kwota  Kwota::operator+  (const Kwota&  inna_kwota) const
{}
Kwota& Kwota::operator-= (const Kwota&  inna_kwota)
{}
Kwota  Kwota::operator-  (const Kwota&  inna_kwota) const
{}
Kwota& Kwota::operator*= (const Kwota&  inna_kwota)
{}
Kwota  Kwota::operator*  (const Kwota&  inna_kwota) const
{}
Kwota& Kwota::operator/= (const Kwota&  inna_kwota)
{}
Kwota  Kwota::operator/  (const Kwota&  inna_kwota) const
{}
Kwota& Kwota::operator%= (const Kwota&  inna_kwota)
{}
Kwota  Kwota::operator%  (const Kwota&  inna_kwota) const
{}
Kwota& Kwota::operator++ ()
{}
Kwota  Kwota::operator++(int)
{}
Kwota& Kwota::operator-- ()
{}
Kwota  Kwota::operator--(int)
{}

bool Kwota::operator== (const Kwota&  inna_kwota) const
{}
bool Kwota::operator!= (const Kwota&  inna_kwota) const
{}
bool Kwota::operator<  (const Kwota&  inna_kwota) const
{}
bool Kwota::operator>  (const Kwota&  inna_kwota) const
{}
bool Kwota::operator<= (const Kwota&  inna_kwota) const
{}
bool Kwota::operator>= (const Kwota&  inna_kwota) const
{}

std::ostream& operator<<(std::ostream& os, Kwota& Kwota)
{}


int Kwota::daj_grosze() const
{}

int Kwota::daj_zlote() const
{}

void Kwota::ustaw_grosze(int nowe_grosze)
{
  if (nowe_grosze >= 100)
  {
    int zl = nowe_grosze / 100;
    int gr = nowe_grosze % 100;
  }
  else
  { grosze = nowe_grosze ;}
}

void Kwota::ustaw_zlote(int nowe_zlote)
{ zlote = nowe_zlote  ;}


