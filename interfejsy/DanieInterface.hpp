#pragma once
#include "Danie.hpp"
class Danie
{
    virtual KategoriaPotrawy    daj_kategorie() = 0;
    virtual Kwota               daj_koszt_przygotowania() = 0;
    virtual unsigned int        daj_czas_przygotowania() = 0;
    virtual unsigned int        daj_czas_oczekiwania() = 0;
    virtual unsigned int        daj_postep_przygotowania() = 0;
    virtual unsigned int        daj_identyfikator() = 0;
    virtual string              daj_nazwe() = 0;
    virtual bool                czy_przygotowane() = 0;

    virtual void ustaw_kategorie(KategoriaPotrawy nowa_kategoria) = 0;
    virtual void ustaw_koszt_przygotowania(Kwota nowy_koszt_przygotowania) = 0;
    virtual void ustaw_czas_przygotowania(unsigned int nowy_czas_przygotowania) = 0;
    virtual void ustaw_czas_oczekiwania(unsigned int new_czas_oczekiwania) = 0;
    virtual void ustaw_postep_przygotowania(unsigned int nowy_postep_przygotowania) = 0;
    virtual void ustaw_czy_przygotowane(bool nowy_status) = 0;
    virtual void ustaw_nazwe(string nowa_nazwa) = 0;

    virtual Kwota         policz_cene() = 0;
    virtual int           policz_priorytet() = 0;
    virtual void          przygotowuj() = 0;
    virtual void          wyswietl() = 0;

};