#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Deser.hpp"

Deser::Deser(string nazwa, unsigned int koszt_przygotowania):
Danie(nazwa, koszt_przygotowania, 3, BazaKategoriiPotraw::DESER) {};


void Deser::wyswietl()
{
  cout
  << "Deser o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}