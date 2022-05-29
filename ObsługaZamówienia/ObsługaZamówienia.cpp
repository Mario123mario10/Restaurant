#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "ObsługaZamówienia.h"
#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"

using namespace std;
using SZ = StatusZamowienia;


ObslugaZamowienia::ObslugaZamowienia()
{}

ObslugaZamowienia::ObslugaZamowienia(unique_ptr<Stolik> stolik, unique_ptr<Klient> klient)
{

  this -> status = SZ::oczekiwanie_na_menu;
  this -> przypisany_stolik.swap(stolik);
  this -> klienci.push_back(move(klient));
  numer_zamowienia = licznik_zamowien + 1;
  licznik_zamowien++;
}

unsigned int ObslugaZamowienia::daj_numer_zamowienia()
{
  return numer_zamowienia;
}

unsigned int ObslugaZamowienia::daj_ilosc_osob_przy_stoliku()
{
  return (klienci.size());
}

StatusZamowienia ObslugaZamowienia::daj_status()
{
  return status;
}

unique_ptr<Stolik> ObslugaZamowienia::zwolnij_stolik()
{
  unique_ptr<Stolik> wskaznik;
  przypisany_stolik.swap(wskaznik);
  return wskaznik;
}

unique_ptr<Kelner> ObslugaZamowienia::zwolnij_kelnera()
{
  unique_ptr<Kelner> wskaznik;
  przypisany_kelner.swap(wskaznik);
  return wskaznik;
}

Kwota ObslugaZamowienia::oblicz_kwote_do_zaplaty()
{
  Kwota cala_kwota(0, 0);
  for (unique_ptr<Danie>& potrawa: zamowione_dania)
  {
    cala_kwota += potrawa -> policz_cene();
  }
  return cala_kwota;
}

void ObslugaZamowienia::przydziel_kelnera(unique_ptr<Kelner> kelner)
{
  przypisany_kelner.swap(kelner);
}

bool ObslugaZamowienia::przydzielony_kelner()
{ return przypisany_kelner != nullptr; }

unsigned int ObslugaZamowienia::daj_numer_kelnera()
{ return przypisany_kelner -> daj_id()  ;}

unsigned int ObslugaZamowienia::daj_numer_stolika()
{ return przypisany_stolik -> daj_numer()  ;}

string ObslugaZamowienia::daj_nazwisko_kelnera()
{
  return (przypisany_kelner -> daj_imie());
}

std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie)
{
  os
  << "Status zamówienia nr " << zamowienie.daj_numer_zamowienia()
  << " i stole nr " << zamowienie.przypisany_stolik -> daj_numer()
  << ":" << endl;

  switch(zamowienie.daj_status())
  {
    case SZ::oczekiwanie_na_menu:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "czekają na menu";
      return os;

    case SZ::zamawianie_dan:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "zamawiają dania";
      return os;

    case SZ::oczekiwanie_na_dania:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os
      << "Oczekują na dania" << endl
      << "Postęp w przygotowaniu dań:" << endl;
      for ( const unique_ptr<Danie>& danie: zamowienie.zamowione_dania  )
      { cout << *danie << endl  ;}
      return os;

    case SZ::przyniesienie_dan:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "Czekają na gotowe dania" << endl;
      if (zamowienie.przydzielony_kelner())
      {
        os
        << zamowienie.daj_nazwisko_kelnera() << " o numerze " << zamowienie.daj_numer_kelnera() << " niesie dania";
      }
      return os;

    case SZ::jedzenie:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "Spożywają posiłek";
      return os;

    case SZ::czekanie_na_rachunek:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "Czekają na rachunek";
      return os;

    case SZ::placenie:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "Płacą za jedzenie: " << zamowienie.oblicz_kwote_do_zaplaty();
      return os;

    case SZ::wyjscie_z_restauracji:
      os << "Klienci:" << endl;
      for (unique_ptr<Klient>& klient: zamowienie.klienci)
      { os << *klient << endl; }
      os << "Wychodzą z restauracji";
      return os;

    case SZ::sprzatanie_stolika:
      os << "Stolik jest sprzątany" << endl;
      return os;
  }
  return os;
}
// oczekiwanie_na_menu,   przydzielić kelnera   +++++++
// zamawianie_dan,        utworzyć dania        +++++++
// oczekiwanie_na_dania,  zwolnić kelnera       +++++++
// przyniesienie_dan,     przypisać kelnera     +++++++
// jedzenie,              zwolnić_kelnera       +++++++
// czekanie_na_rachunek,  przypisać kelnera     +++++++
// placenie,                                    +++++++
// wyjscie_z_restauracji,                       +++++++
// sprzatanie_stolika,                          +++++++
// koniec                 zwolnić kelnera,      ///////
//                        zwolnić stolik



void ObslugaZamowienia::wyswietl_klientow(fstream& plik)
{
  // for (unique_ptr<Klient>& klient: klienci)
  // { plik << *klient << endl; }
}


