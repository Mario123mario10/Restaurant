
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "DanieMięsne.hpp"


DanieMiesne::DanieMiesne(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 8) {}

std::ostream&  operator<<(std::ostream& os, DanieMiesne& Danie)
{
  cout
  << "Danie mięsne o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}
