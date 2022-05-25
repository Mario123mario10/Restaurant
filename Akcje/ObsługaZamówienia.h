#pragma once
#include "InneKlasy.h"
#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"


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
    ObslugaZamowienia()
    {}

    ObslugaZamowienia(Stolik stolik, unsigned int ilosc_osob_przy_stoliku=1)
    {
        status = oczekiwanie_na_menu;
        this -> stolik = stolik;
        this -> ilosc_osob_przy_stoliku = ilosc_osob_przy_stoliku;
        numer_zamowienia = wolny_numer;
        wolny_numer ++;
    }
    unsigned_int daj_numer_zamowienia()
    {
        return numer_zamowienia;
    }

    unsigned int daj_ilosc_osob_przy_stoliku()
    {
        return ilosc_osob_przy_stoliku;
    }

    StatusZamowienia daj_status()
    {
        return status;
    }

    Stolik daj_stolik()
    {
        return stolik;
    }

    Kelner daj_kelnera()
    {
        return kelner;
    }

    void zaplac()
    {
        rachunek.zaplac();
        status = zaplacone;
    }

    void sprzatnij_ze_stolika()
    {
        status = stol_posprzatany;
    }

    Rachunek stworz_rachunek()
    {
        Rachunek rachunek;
        return rachunek;

    }
    void czekanie_na_zaplate()
    {
        status = czekanie_kelnera_na_zaplate;
    }

    void dodaj_nowe_osoby(unsigned int nowe_osoby)
    {
        ilosc_osob_przy_stoliku += nowe_osoby;
    }

    void zakoncz_wszystkie_posilki()
    {
        status = czekanie_na_rachunek;
    }

    void zamow_potrawe(Potrawa* nowa_potrawa, unsigned int ilosc_sztuk)
    {
        zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
        status = oczekiwanie_na_dania;
    }

    void podaj_dania_do_stolika()
    {
        status = jedzenie;
    }

    unsigned int oblicz_kwote_do_zaplaty()
    {
        unsigned int cala_kwota = 0;

        for (auto potrawa_i_ich_ilosc:zamowione_potrawy)
        {
            cala_kwota += potrawa_i_ich_ilosc.second * potrawa_i_ich_ilosc.first.podaj_cene();
        }

        return cala_kwota;
    }

    void przypisz_kelnera_i_zanies_menu(Kelner przypisany_kelner)
    {
        kelner = przypisany_kelner;
        status = czytanie_menu;
    }

};


unsigned int ObslugaZamowienia::wolny_numer=1;