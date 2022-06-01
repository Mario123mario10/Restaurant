#pragma once
#include "ObsługaZamówienia.h"

class InterfejsObslugaZamowienia
{
public:
    virtual StatusZamowienia daj_status() = 0;
    virtual unsigned int daj_numer_zamowienia() = 0;
    virtual unsigned int daj_ilosc_osob_przy_stoliku() = 0;
    virtual unsigned int daj_numer_stolika() = 0;
    virtual unsigned int daj_numer_kelnera() = 0;
    virtual unsigned int policz_czas_jedzenia() = 0;
    virtual string daj_nazwisko_kelnera() = 0;
    virtual bool przydzielony_kelner() = 0;
    virtual bool dla_czekajacych() = 0;
    virtual bool dania_gotowe() = 0;
    virtual Kwota oblicz_kwote_do_zaplaty() = 0;
    virtual unique_ptr<Stolik> zwolnij_stolik() = 0;
    virtual unique_ptr<Kelner> zwolnij_kelnera() = 0;
    virtual void przydziel_kelnera(unique_ptr<Kelner> kelner) = 0;
    virtual void zamow_potrawe(unique_ptr<Danie> nowa_potrawa) = 0;
    virtual void dodaj_klienta(unique_ptr<Klient> klient) = 0;
    virtual void wyswietl_klientow(fstream& plik) = 0;
    virtual void zamowiono() = 0;
    virtual void uplyw_czasu() = 0;
    virtual void przygotowuj_dania() = 0;
    virtual void oczekiwanie_na_menu() = 0;
    virtual void zamawianie_dan() = 0;
    virtual void oczekiwanie_na_dania() = 0;
    virtual void przyniesienie_dan() = 0;
    virtual void jedzenie() = 0;
    virtual void czekanie_na_rachunek() = 0;
    virtual void placenie() = 0;
    virtual void wyjscie_z_restauracji() = 0;
    virtual void sprzatanie_stolika() = 0;
    virtual ~InterfejsObslugaZamowienia() = 0;
};
