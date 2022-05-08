
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "DanieWegetariańskie.hpp"

DanieWegetarianskie::DanieWegetarianskie(string nazwa, unsigned int koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 4) {}

void DanieWegetarianskie::wyswietl()
{
  cout
  << "Danie wegetariańskie o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}