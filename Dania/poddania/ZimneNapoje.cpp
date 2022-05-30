#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "ZimneNapoje.hpp"

ZimnyNapoj::ZimnyNapoj(string nazwa, Kwota koszt_przygotowania):
  Napoj(nazwa, koszt_przygotowania, 1) {};


std::ostream&  operator<<(std::ostream& os, ZimnyNapoj& Danie)
{
  os
  << "Zimny napój o nazwie: "
  << Danie.daj_nazwe()
  << " kosztuje: "
  << (string) Danie.policz_cene();
  return os;
}

