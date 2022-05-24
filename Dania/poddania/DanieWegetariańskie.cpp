
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "DanieWegetariańskie.hpp"

DanieWegetarianskie::DanieWegetarianskie(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 4) {}

void DanieWegetarianskie::wyswietl()
{
  cout
  << "Danie wegetariańskie o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << (string) policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}