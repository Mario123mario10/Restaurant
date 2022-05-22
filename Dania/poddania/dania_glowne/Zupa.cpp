#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Zupa.hpp"

Zupa::Zupa(string nazwa, Kwota koszt_przygotowania):
  DanieGlowne(nazwa, koszt_przygotowania, 4) {}

void Zupa::wyswietl()
{
  cout
  << "Zupa o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << (string) policz_cene()
  << " i ma priorytet "
  << policz_priorytet()
  << endl;
}