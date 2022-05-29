#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
//#include "Obsluga_zamowienia.h"

class Potrawa
{
    unsigned int cena_potrawy;
    string nazwa_potrawy;

public:
    Potrawa();

    Potrawa(unsigned int cena_potrawy, string nazwa_potrawy);

    unsigned int podaj_cene();

    string podaj_nazwe();
};

class Zupa: public Potrawa
{
public:
    Zupa();
    Zupa(unsigned int cena_potrawy, string nazwa_potrawy);

};

// class Deser: public Potrawa
// {

// };

// class Napoj: public Potrawa
// {

// };

// class Drugie_danie: public Potrawa
// {

// };

// class Przystawka: public Potrawa
// {

// };


enum Status_zamowienia
{
    oczekiwanie_na_menu,
    czytanie_menu,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    czekanie_kelnera_na_zaplate,
    zaplacone,
    //placenie,
    wyjscie_z_restauracji,
    stol_posprzatany
};


class Kelner
{

    unsigned int numer_id;
    string imie;
    bool czy_wolny;  // moze przyjsc do kazdego zamowienia
    //vector <Obsluga_zamowienia> trwajace_zamowienia;
public:
    Kelner();

    Kelner(string imie);

    string daj_imie();


};
enum Wielkosc_stolika
{
    maly,
    duzy,
    sredni
};


class Stolik
{
    unsigned int numer;
    unsigned int ilosc_miejsc;
    bool wolny;
    Wielkosc_stolika wielkosc_stolika;

public:
    Stolik();

    Stolik(unsigned int numer, unsigned int ilosc_miejsc, bool wolny=true);

    unsigned int daj_numer();

    unsigned int daj_ilosc_miejsc();

    bool czy_wolny();
};


class Pozycja_rachunku
{
    Potrawa danie;
    unsigned int ilosc_sztuk;
};


class Rachunek
{
    vector <Pozycja_rachunku> lista_produktow;
    unsigned int cena_laczna;
    bool czy_rachunek_zaplacony;
public:
    Rachunek();

    void wyswietl();

    void zaplac();
};
