#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "CiepłeNapoje.hpp"
#include "../../Kwota/Kwota.h"

CieplyNapoj::CieplyNapoj(string nazwa, Kwota koszt_przygotowania):
  Napoj(nazwa, koszt_przygotowania, 2) {}

void CieplyNapoj::wyswietl()
{
  cout
  << "Ciepły Napój o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << (string) policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}

