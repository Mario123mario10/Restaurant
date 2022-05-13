
#include "Kwota.h"


using std::to_string;


Kwota::Kwota()
{
  zlote = 0;
  grosze = 0;
}

Kwota::Kwota(int zlote, int grosze)
{ // dodać warian ujemny
  this -> zlote = zlote;
  this -> grosze = grosze;
}

Kwota::Kwota(int a_grosze)
{

  ustaw_grosze(a_grosze);
}

// Kwota::Kwota(float kwota)
// {}

Kwota::operator string()
{ return to_string(zlote) + " zł " + to_string(grosze) + " gr" ;}

Kwota& Kwota::operator+= (const Kwota&  inna_kwota)
{
  zlote += inna_kwota.daj_zlote();
  ustaw_grosze(grosze + inna_kwota.daj_grosze());
}

Kwota  Kwota::operator+  (const Kwota&  inna_kwota) const
{
  Kwota kwota = *this;
  kwota += inna_kwota;
  return kwota;
}

Kwota& Kwota::operator-= (const Kwota&  inna_kwota)
{
  zlote -= inna_kwota.daj_zlote();
  ustaw_grosze(grosze - inna_kwota.daj_grosze());
}

Kwota  Kwota::operator-  (const Kwota&  inna_kwota) const
{
  Kwota kwota = *this;
  kwota -= inna_kwota;
  return kwota;
}

Kwota& Kwota::operator*= (const Kwota&  inna_kwota)
{
  // zlote *= inna_kwota.daj_zlote();
  // ustaw_grosze(grosze - inna_kwota.daj_grosze());
}

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
{ return (zlote == inna_kwota.daj_zlote() and grosze == inna_kwota.daj_grosze()) ;}

bool Kwota::operator!= (const Kwota&  inna_kwota) const
{ return not (*this == inna_kwota)  ;}
bool Kwota::operator<  (const Kwota&  inna_kwota) const
{

}
bool Kwota::operator>  (const Kwota&  inna_kwota) const
{}
bool Kwota::operator<= (const Kwota&  inna_kwota) const
{}
bool Kwota::operator>= (const Kwota&  inna_kwota) const
{}

std::ostream& operator<<(std::ostream& os, Kwota& Kwota)
{}


int Kwota::daj_grosze() const
{ return grosze ;}

int Kwota::daj_zlote() const
{ return zlote  ;}

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


