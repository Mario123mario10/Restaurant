
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "DanieWegetariańskie.hpp"

DanieWegetarianskie::DanieWegetarianskie(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 3) {}


std::ostream&  operator<<(std::ostream& os, DanieWegetarianskie& Danie)
{
  os
  << "Danie wegetariańskie o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}

