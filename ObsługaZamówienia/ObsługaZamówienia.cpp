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

ObslugaZamowienia::ObslugaZamowienia(Stolik& stolik, unique_ptr<Klient> klient)
{

  status = SZ::oczekiwanie_na_menu;
  this -> stolik = stolik;
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

Stolik ObslugaZamowienia::daj_stolik()
{
  return stolik;
}

Kelner ObslugaZamowienia::daj_kelnera()
{
  return kelner;
}



void ObslugaZamowienia::sprzatnij_ze_stolika()
{
  status = SZ::sprzatanie_stolika;
}


void ObslugaZamowienia::zamow_potrawe(unique_ptr<Danie> nowa_potrawa, unsigned int ilosc_sztuk)
{
  // zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
  status = SZ::oczekiwanie_na_dania;
}

void ObslugaZamowienia::podaj_dania_do_stolika()
{
  status = SZ::jedzenie;
}

unsigned int ObslugaZamowienia::oblicz_kwote_do_zaplaty()
{
  unsigned int cala_kwota = 0;

  // for (auto& potrawa_i_ich_ilosc:zamowione_potrawy)
  // {
  //     cala_kwota += potrawa_i_ich_ilosc.second * potrawa_i_ich_ilosc.first -> podaj_cene();
  // }

  return cala_kwota;
}


std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie)
{
  os
  << "Status zamówienia nr " << zamowienie.daj_numer_zamowienia()
  << " i stole nr " << zamowienie.stolik.daj_numer()
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
      // for (const unique_ptr<Danie>& danie: zamowienie.zamowione_dania)
      // {

      // }
      ;
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

    // case SZ::czekanie_kelnera_na_zaplate:

    //   return os;

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
      os << "Klienci " << endl;

      return os;
  }
  return os;
}
