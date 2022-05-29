#include <string>

#include "Kwota.h"
#include "Bledy.h"

using std::to_string;


Kwota::Kwota()
{
  this -> zlote   = 0;
  this -> grosze  = 0;
}

Kwota::Kwota(int zlote, int grosze)
{
  if (zlote >= 0 and grosze >= 0)
  {
    ustaw_zlote(zlote);
    ustaw_grosze(grosze = grosze);
  }
  else if (zlote <= 0 and grosze <= 0)
  {
    ustaw_zlote(zlote);
    ustaw_grosze(grosze = grosze);
  }
  else
  { throw NiepoprawnaKwota(*this) ;}
}

Kwota::operator string() const
{ return to_string(zlote) + " zł " + to_string(grosze) + " gr" ;}

Kwota& Kwota::operator+= (const Kwota&  inna_kwota)
{
  zlote += inna_kwota.daj_zlote();
  ustaw_grosze(grosze + inna_kwota.daj_grosze());
  return *this;
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
  return *this;
}

Kwota  Kwota::operator-  (const Kwota&  inna_kwota) const
{
  Kwota kwota = *this;
  kwota -= inna_kwota;
  return kwota;
}

Kwota& Kwota::operator+= (int liczba)
{
  *this += Kwota(liczba, 0);
  return *this;
}

Kwota  Kwota::operator+  (int liczba)   const
{
  Kwota nowa_kwota(liczba, 0);
  nowa_kwota += *this;
  return nowa_kwota;
}

Kwota& Kwota::operator-= (int liczba)
{
  *this -= Kwota(liczba, 0);
  return *this;
}

Kwota  Kwota::operator-  (int liczba)   const
{
  Kwota nowa_kwota(liczba, 0);
  nowa_kwota -= *this;
  return nowa_kwota;
}

Kwota& Kwota::operator*= (int mnoznik)
{
  int nowe_grosze = jako_grosze() * mnoznik;
  zlote = 0;
  ustaw_grosze(nowe_grosze);
  return *this;
}

Kwota  Kwota::operator*  (int mnoznik) const
{
  Kwota nowa_kwota(daj_zlote(), daj_grosze());
  nowa_kwota *= mnoznik;
  return nowa_kwota;
}

Kwota& Kwota::operator/= (int dzielna)
{
  int nowe_grosze = jako_grosze() / dzielna;
  zlote = 0;
  ustaw_grosze(nowe_grosze);
  return *this;
}

Kwota  Kwota::operator/  (int dzielna) const
{
  Kwota nowa_kwota(daj_zlote(), daj_grosze());
  nowa_kwota /= dzielna;
  return nowa_kwota;
}



bool Kwota::operator== (const Kwota&  inna_kwota) const
{ return (zlote == inna_kwota.daj_zlote() and grosze == inna_kwota.daj_grosze()) ;}

bool Kwota::operator!= (const Kwota&  inna_kwota) const
{ return not (*this == inna_kwota)  ;}

bool Kwota::operator== (int liczba) const
{ return (zlote == liczba and grosze == liczba) ;}

bool Kwota::operator!= (int liczba) const
{ return not (*this == liczba)  ;}

bool Kwota::operator<  (const Kwota&  inna_kwota) const
{
  return
  ( zlote < inna_kwota.daj_zlote())
  or
  ( (zlote == inna_kwota.daj_zlote()) and (grosze < inna_kwota.daj_grosze()));
}

bool Kwota::operator>  (const Kwota&  inna_kwota) const
{ return not (*this <= inna_kwota)  ;}

bool Kwota::operator<= (const Kwota&  inna_kwota) const
{ return ((*this < inna_kwota) or (*this == inna_kwota))  ;}

bool Kwota::operator>= (const Kwota&  inna_kwota) const
{ return not (*this < inna_kwota) ;}

std::ostream& operator<<(std::ostream& os, const Kwota& Kwota)
{
  string napis = (string) Kwota;
  os << napis;
  return os;
}


int Kwota::daj_grosze() const
{ return grosze ;}

int Kwota::daj_zlote() const
{ return zlote  ;}

void Kwota::ustaw_grosze(int nowe_grosze)
{
  if (zlote >= 0)
  {
    if (nowe_grosze >= 100)
    {
      zlote += nowe_grosze / 100;
      grosze = nowe_grosze % 100;
    }
    else if (nowe_grosze >= 0)
    { grosze = nowe_grosze ;}
    else
    { throw NiepoprawnaKwota(nowe_grosze)  ;}
  }
  else
  {
    if (nowe_grosze <= -100)
    {
      zlote += nowe_grosze / 100;
      grosze = nowe_grosze % 100;
    }
    else if (nowe_grosze <= 0)
    { grosze = nowe_grosze ;}
    else
    { throw NiepoprawnaKwota(nowe_grosze)  ;}

  }

}

void Kwota::ustaw_zlote(int nowe_zlote)
{ zlote = nowe_zlote  ;}

int Kwota::jako_grosze() const
{ return (zlote * 100 + grosze); }
