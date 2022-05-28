#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
using std::unique_ptr ;

#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "../Klient/Klient.h"

enum class StatusZamowienia
{
    oczekiwanie_na_menu,
    zamawianie_dan,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    placenie,
    wyjscie_z_restauracji,
    sprzatanie_stolika
};

using SZ = StatusZamowienia;

class ObslugaZamowienia //zamowienie rozpoczyna sie juz po usiedzeniu przy stoliku
{
    unsigned int numer_zamowienia;
    // map <unique_ptr<Danie>, unsigned int> zamowione_dania; // zamowione potrawy i ich ilosc
    vector<unique_ptr<Klient>> klienci;
    Stolik stolik;
    Kelner kelner;
    StatusZamowienia status;

    // static unsigned int wolny_numer;

public:
    ObslugaZamowienia();
    ObslugaZamowienia(Stolik& stolik, unique_ptr<Klient> klient, unsigned int numer_zamowienia);
    unsigned int daj_numer_zamowienia();
    unsigned int daj_ilosc_osob_przy_stoliku();
    StatusZamowienia daj_status();



    Stolik daj_stolik();
    Kelner daj_kelnera();
    void zaplac();
    void sprzatnij_ze_stolika();
    void czekanie_na_zaplate();
    void zakoncz_wszystkie_posilki();
    void zamow_potrawe(unique_ptr<Danie> nowa_potrawa, unsigned int ilosc_sztuk);
    void podaj_dania_do_stolika();
    unsigned int oblicz_kwote_do_zaplaty();

    void uplyw_czasu();


    friend std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie);

};

