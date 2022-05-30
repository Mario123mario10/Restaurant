#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Zupa.hpp"

Zupa::Zupa(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 4) {}



std::ostream& operator<<(std::ostream& os, Zupa& Danie)
{
  os
  << "Zupa o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}