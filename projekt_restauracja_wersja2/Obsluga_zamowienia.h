
#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#include <memory>
using std::unique_ptr;

#include "Inne_klasy.h"

class Obsluga_zamowienia //zamowienie rozpoczyna sie juz po usiedzeniu przy stoliku
{
    unsigned int numer_zamowienia;
    static unsigned int wolny_numer;
    map <unique_ptr<Potrawa>, unsigned int> zamowione_potrawy; // zamowione potrawy i ich ilosc
    unsigned int ilosc_osob_przy_stoliku;
    Stolik stolik;
    Status_zamowienia status;
    Kelner kelner;
    Rachunek rachunek;


public:
    Obsluga_zamowienia();

    Obsluga_zamowienia(Stolik stolik, unsigned int ilosc_osob_przy_stoliku=1);

    unsigned int daj_numer_zamowienia();


    unsigned int daj_ilosc_osob_przy_stoliku();

    Status_zamowienia daj_status();

    Stolik daj_stolik();

    Kelner daj_kelnera();

    void zaplac();

    void sprzatnij_ze_stolika();

    Rachunek stworz_rachunek();

    void czekanie_na_zaplate();

    void dodaj_nowe_osoby(unsigned int nowe_osoby);

    void zakoncz_wszystkie_posilki();

    void zamow_potrawe(unique_ptr<Potrawa> nowa_potrawa, unsigned int ilosc_sztuk);

    void podaj_dania_do_stolika();

    unsigned int oblicz_kwote_do_zaplaty();

    void przypisz_kelnera_i_zanies_menu(Kelner przypisany_kelner);

};
