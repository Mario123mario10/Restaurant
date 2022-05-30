#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Przystawka.hpp"
#include "../../Kwota/Kwota.h"


Przystawka::Przystawka(string nazwa, Kwota koszt_przygotowania):
  Danie(nazwa, koszt_przygotowania, 2, KategoriaPotrawy::PRZYSTAWKA) {}



std::ostream&  operator<<(std::ostream& os, Przystawka& Danie)
{
  os
  << "Przystawka o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}


