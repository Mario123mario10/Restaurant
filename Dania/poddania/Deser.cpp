#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Deser.hpp"

Deser::Deser(string nazwa, Kwota koszt_przygotowania):
Danie(nazwa, koszt_przygotowania, 3, KategoriaPotrawy::DESER) {};


void Deser::wyswietl()
{
  cout
  << "Deser o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << (string) policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}
