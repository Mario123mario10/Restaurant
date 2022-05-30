#pragma once

#include <string>
#include <vector>
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
    bool czekajacy;
    unsigned int obsluzeni_klienci;
    unsigned int czas_jedzenia;
    unsigned int czas_sprzatania;
    unsigned int numer_zamowienia;
    static unsigned int licznik_zamowien;
public:
    vector<unique_ptr<Danie>> zamowione_dania;
    ObslugaZamowienia();
    ObslugaZamowienia(unique_ptr<Stolik> stolik, unique_ptr<Klient> klient);
    StatusZamowienia daj_status();
    unsigned int daj_numer_zamowienia();
    unsigned int daj_ilosc_osob_przy_stoliku();
    unsigned int daj_numer_stolika();
    unsigned int daj_numer_kelnera();
    unsigned int policz_czas_jedzenia();
    string daj_nazwisko_kelnera();
    bool przydzielony_kelner();
    bool dla_czekajacych();
    bool dania_gotowe();
    Kwota oblicz_kwote_do_zaplaty();
    unique_ptr<Stolik> zwolnij_stolik();
    unique_ptr<Kelner> zwolnij_kelnera();
    void przydziel_kelnera(unique_ptr<Kelner> kelner);
    void zamow_potrawe(unique_ptr<Danie> nowa_potrawa);
    void dodaj_klienta(unique_ptr<Klient> klient);
    void wyswietl_klientow(fstream& plik);
    void zamowiono();
    void uplyw_czasu();
    void przygotowuj_dania();
    void oczekiwanie_na_menu();
    void zamawianie_dan();
    void oczekiwanie_na_dania();
    void przyniesienie_dan();
    void jedzenie();
    void czekanie_na_rachunek();
    void placenie();
    void wyjscie_z_restauracji();
    void sprzatanie_stolika();

    friend std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie);
};

