#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "ObsługaZamówienia.h"
#include "InneKlasy.h"
#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "SzkicePotraw.h"

using namespace std;
using SZ = StatusZamowienia;


ObslugaZamowienia::ObslugaZamowienia() {}

ObslugaZamowienia::ObslugaZamowienia(Stolik stolik, unsigned int ilosc_osob_przy_stoliku)
{
    status = SZ::oczekiwanie_na_menu;
    this -> stolik = stolik;
    this -> ilosc_osob_przy_stoliku = ilosc_osob_przy_stoliku;
    numer_zamowienia = wolny_numer;
    wolny_numer ++;
}
unsigned int ObslugaZamowienia::daj_numer_zamowienia()
{
    return numer_zamowienia;
}

unsigned int ObslugaZamowienia::daj_ilosc_osob_przy_stoliku()
{
    return ilosc_osob_przy_stoliku;
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

void ObslugaZamowienia::zaplac()
{
    rachunek.zaplac();
    status = SZ::zaplacone;
}

void ObslugaZamowienia::sprzatnij_ze_stolika()
{
    status = SZ::stol_posprzatany;
}

Rachunek ObslugaZamowienia::stworz_rachunek()
{
    Rachunek rachunek;
    return rachunek;

}
void ObslugaZamowienia::czekanie_na_zaplate()
{
    status = SZ::czekanie_kelnera_na_zaplate;
}

void ObslugaZamowienia::dodaj_nowe_osoby(unsigned int nowe_osoby)
{
    ilosc_osob_przy_stoliku += nowe_osoby;
}

void ObslugaZamowienia::zakoncz_wszystkie_posilki()
{
    status = SZ::czekanie_na_rachunek;
}

void ObslugaZamowienia::zamow_potrawe(Potrawa* nowa_potrawa, unsigned int ilosc_sztuk)
{
    zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
    status = SZ::oczekiwanie_na_dania;
}

void ObslugaZamowienia::podaj_dania_do_stolika()
{
    status = SZ::jedzenie;
}

unsigned int ObslugaZamowienia::oblicz_kwote_do_zaplaty()
{
    unsigned int cala_kwota = 0;

    for (auto potrawa_i_ich_ilosc:zamowione_potrawy)
    {
        cala_kwota += potrawa_i_ich_ilosc.second * potrawa_i_ich_ilosc.first -> podaj_cene();
    }

    return cala_kwota;
}

void ObslugaZamowienia::przypisz_kelnera_i_zanies_menu(Kelner przypisany_kelner)
{
    kelner = przypisany_kelner;
    status = SZ::czytanie_menu;
}

std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie)
{
  switch(zamowienie.daj_status())
  {
    case SZ::oczekiwanie_na_menu:
    return os;

    case SZ::czytanie_menu:
    return os;

    case SZ::oczekiwanie_na_dania:
    return os;

    case SZ::jedzenie:
    return os;

    case SZ::czekanie_na_rachunek:
    return os;

    case SZ::czekanie_kelnera_na_zaplate:
    return os;

    case SZ::zaplacone:
    return os;

    case SZ::wyjscie_z_restauracji:
    return os;

    case SZ::stol_posprzatany:
    return os;

  }

}
