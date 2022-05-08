#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Przystawka.hpp"

Przystawka::Przystawka(string nazwa, unsigned int koszt_przygotowania):
  Danie(nazwa, koszt_przygotowania, 2, KategoriaPotrawy::PRZYSTAWKA) {}

void Przystawka::wyswietl()
{
  cout
  << "Przystawka o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}
