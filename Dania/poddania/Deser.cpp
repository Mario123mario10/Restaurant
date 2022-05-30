#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "Deser.hpp"

Deser::Deser(string nazwa, Kwota koszt_przygotowania):
Danie(nazwa, koszt_przygotowania, 3, KategoriaPotrawy::DESER) {};




std::ostream&  operator<<(std::ostream& os, Deser& Danie)
{
  os
  << "Deser o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}



