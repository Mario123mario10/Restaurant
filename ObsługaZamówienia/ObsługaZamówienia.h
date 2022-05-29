#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>

#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "../Klient/Klient.h"

using namespace std;

enum class StatusZamowienia
{
    oczekiwanie_na_menu,
    zamawianie_dan,
    oczekiwanie_na_dania,
    przyniesienie_dan,
    jedzenie,
    czekanie_na_rachunek,
    placenie,
    wyjscie_z_restauracji,
    sprzatanie_stolika,
    koniec
};

using SZ = StatusZamowienia;

class ObslugaZamowienia
{
    vector<unique_ptr<Klient>> klienci;
    unique_ptr<Stolik> przypisany_stolik;
    unique_ptr<Kelner> przypisany_kelner;
    StatusZamowienia status;
    unsigned int numer_zamowienia;
    unsigned int licznik_zamowien;

public:
    vector<unique_ptr<Danie>> zamowione_dania;
    ObslugaZamowienia();
    ObslugaZamowienia(unique_ptr<Stolik> stolik, unique_ptr<Klient> klient);
    StatusZamowienia daj_status();
    unsigned int daj_numer_zamowienia();
    unsigned int daj_ilosc_osob_przy_stoliku();
    unsigned int daj_numer_stolika();
    unsigned int daj_numer_kelnera();
    string daj_nazwisko_kelnera();
    bool przydzielony_kelner();
    void przydziel_kelnera(unique_ptr<Kelner> kelner);
    Kwota oblicz_kwote_do_zaplaty();
    unique_ptr<Stolik> zwolnij_stolik();
    unique_ptr<Kelner> zwolnij_kelnera();
    void zamow_potrawe(unique_ptr<Danie> nowa_potrawa);



    void wyswietl_klientow(fstream& plik);



    void zaplac();
    void sprzatnij_ze_stolika();
    void czekanie_na_zaplate();
    void zakoncz_wszystkie_posilki();

    void uplyw_czasu();

    friend std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie);

};

