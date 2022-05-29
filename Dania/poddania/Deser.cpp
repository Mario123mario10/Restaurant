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

std::ostream&  operator<<(std::ostream& os, Deser& Danie)
{
  os
  << "Deser o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene()
  << " i ma priorytet: "
  << Danie.policz_priorytet();
  return os;
}



