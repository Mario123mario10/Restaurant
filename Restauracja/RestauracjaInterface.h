#pragma once
#include "Restauracja.h"

class InterfejsRestauracja
{
public:
    virtual void uplyw_czasu() = 0;

    virtual void pokaz_bezczynnych_kelnerow() = 0;
    virtual void pokaz_status_zamowien() = 0;
    virtual void pokaz_wolne_stoliki() = 0;
    virtual void pokaz_nieobslugiwanych_klientow() = 0;
    virtual void pokaz_wchodzacych_klientow() = 0;

    virtual void dodaj_klienta(unique_ptr<Klient> wchodzacy_klient) = 0;
    virtual void dodaj_kelnera(unique_ptr<Kelner> kelner) = 0;
    virtual void dodaj_stolik(unique_ptr<Stolik> stolik) = 0;
    virtual void dodaj_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik) = 0;

    virtual void sprawdz_klientow() = 0;
    virtual void sprawdz_kelnerow() = 0;
    virtual void sprawdz_zamowienia() = 0;

    virtual void aktywuj_obslugi_zamowien() = 0;

    virtual void przydziel_klientow() = 0;
    virtual void posprzataj_zamowienia() = 0;

    virtual void posprzataj_klientow() = 0;

    virtual unique_ptr<Kelner> przekaz_kelnera() = 0;
    virtual unsigned int daj_ilosc_aktualnych_zamowien() = 0;
    virtual ~InterfejsRestauracja() = 0;

};

