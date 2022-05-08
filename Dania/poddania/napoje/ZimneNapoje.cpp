#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "ZimneNapoje.hpp"

ZimnyNapoj::ZimnyNapoj(string nazwa, unsigned int koszt_przygotowania):
  Napoj(nazwa, koszt_przygotowania, 1) {};

void ZimnyNapoj::wyswietl()
{
  cout
  << "Zimny napój o nazwie: "
  << daj_nazwe()
  << " kosztuje: "
  << policz_cene()
  << " i ma priorytet: "
  << policz_priorytet()
  << endl;
}
