#include <string>
using std::string;

#include "Klient.h"


Klient::Klient(string imie, bool dosiada_sie)
{
  this -> imie = imie;
  this -> dosiada_sie = dosiada_sie;
  this -> identyfikator = licznik_klientow;
  licznik_klientow++;
}

bool Klient::czy_dosiada_sie()
{ return dosiada_sie  ;}

string Klient::daj_imie()
{ return imie ;}

unsigned int Klient::daj_identyfikator()
{ return identyfikator ;}
