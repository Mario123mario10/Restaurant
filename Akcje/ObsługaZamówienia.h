#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "InneKlasy.h"
#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "SzkicePotraw.h"
#include "Rachunek.h"

enum class StatusZamowienia
{
    oczekiwanie_na_menu,
    czytanie_menu,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    czekanie_kelnera_na_zaplate,
    zaplacone,
    wyjscie_z_restauracji,
    stol_posprzatany
};



using SZ = StatusZamowienia;




class ObslugaZamowienia //zamowienie rozpoczyna sie juz po usiedzeniu przy stoliku
{
    unsigned int numer_zamowienia;
    static unsigned int wolny_numer;
    map <Potrawa*, unsigned int> zamowione_potrawy; // zamowione potrawy i ich ilosc
    unsigned int ilosc_osob_przy_stoliku;
    Stolik stolik;
    StatusZamowienia status;
    Kelner kelner;
    Rachunek rachunek;


public:
    ObslugaZamowienia();

    ObslugaZamowienia(Stolik stolik, unsigned int ilosc_osob_przy_stoliku=1);
    unsigned int daj_numer_zamowienia();
    unsigned int daj_ilosc_osob_przy_stoliku();
    StatusZamowienia daj_status();
    Stolik daj_stolik();
    Kelner daj_kelnera();
    void zaplac();
    void sprzatnij_ze_stolika();
    Rachunek stworz_rachunek();
    void czekanie_na_zaplate();
    void dodaj_nowe_osoby(unsigned int nowe_osoby);
    void zakoncz_wszystkie_posilki();
    void zamow_potrawe(Potrawa* nowa_potrawa, unsigned int ilosc_sztuk);
    void podaj_dania_do_stolika();
    unsigned int oblicz_kwote_do_zaplaty();
    void przypisz_kelnera_i_zanies_menu(Kelner przypisany_kelner);

};


// unsigned int ObslugaZamowienia::wolny_numer=1;