#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "CiepłeNapoje.hpp"
#include "../../Kwota/Kwota.h"

CieplyNapoj::CieplyNapoj(string nazwa, Kwota koszt_przygotowania):
  Napoj(nazwa, koszt_przygotowania, 2) {}

std::ostream&  operator<<(std::ostream& os, CieplyNapoj& Danie)
{
  cout
  << "Ciepły Napój o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}

