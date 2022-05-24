
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "DanieMięsne.hpp"


DanieMiesne::DanieMiesne(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 8) {}

void DanieMiesne::wyswietl()
{
  cout
  << "Danie mięsne o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << (string) policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}
