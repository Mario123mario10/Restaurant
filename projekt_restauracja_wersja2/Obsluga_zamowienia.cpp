


#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
//#include "Inne_klasy.h"

#include "Obsluga_zamowienia.h"

Obsluga_zamowienia::Obsluga_zamowienia()
{}

Obsluga_zamowienia::Obsluga_zamowienia(Stolik stolik, unsigned int ilosc_osob_przy_stoliku)
{
    status = oczekiwanie_na_menu;
    this -> stolik = stolik;
    this -> ilosc_osob_przy_stoliku = ilosc_osob_przy_stoliku;
    numer_zamowienia = wolny_numer;
    wolny_numer ++;
}
unsigned int Obsluga_zamowienia::daj_numer_zamowienia()
{
    return numer_zamowienia;
}

unsigned int Obsluga_zamowienia::daj_ilosc_osob_przy_stoliku()
{
    return ilosc_osob_przy_stoliku;
}

Status_zamowienia Obsluga_zamowienia::daj_status()
{
    return status;
}

Stolik Obsluga_zamowienia::daj_stolik()
{
    return stolik;
}

Kelner Obsluga_zamowienia::daj_kelnera()
{
    return kelner;
}

void Obsluga_zamowienia::zaplac()
{
    rachunek.zaplac();
    status = zaplacone;
}

void Obsluga_zamowienia::sprzatnij_ze_stolika()
{
    status = stol_posprzatany;
}

Rachunek Obsluga_zamowienia::stworz_rachunek()
{
    Rachunek rachunek;
    return rachunek;

}
void Obsluga_zamowienia::czekanie_na_zaplate()
{
    status = czekanie_kelnera_na_zaplate;
}

void Obsluga_zamowienia::dodaj_nowe_osoby(unsigned int nowe_osoby)
{
    ilosc_osob_przy_stoliku += nowe_osoby;
}

void Obsluga_zamowienia::zakoncz_wszystkie_posilki()
{
    status = czekanie_na_rachunek;
}

void Obsluga_zamowienia::zamow_potrawe(unique_ptr<Potrawa> nowa_potrawa, unsigned int ilosc_sztuk)
{
    zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
    status = oczekiwanie_na_dania;
}

void Obsluga_zamowienia::podaj_dania_do_stolika()
{
    status = jedzenie;
}

unsigned int Obsluga_zamowienia::oblicz_kwote_do_zaplaty()
{
    unsigned int cala_kwota = 0;

    for (map<unique_ptr<Potrawa>, unsigned int>::iterator i= zamowione_potrawy.begin(); i!= zamowione_potrawy.end(); i++)
    {
        cala_kwota += (*i).second * (*i).first -> podaj_cene();
    }

    // for( map<int, float>::iterator i= Students.begin(); i != Students.end(); i++)

    return cala_kwota;
}

void Obsluga_zamowienia::przypisz_kelnera_i_zanies_menu(Kelner przypisany_kelner)
{
    kelner = przypisany_kelner;
    status = czytanie_menu;
}



unsigned int Obsluga_zamowienia::wolny_numer=1;