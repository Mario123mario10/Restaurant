#pragma once
#include "ObsługaWejściowa.h"

class ObslugaWejsciowa
{
public:
    virtual string daj_nazwe_pliku_wyjscia();
    virtual string daj_nazwe_restauracji();
    virtual unsigned int daj_rozmiar_maly();
    virtual unsigned int daj_rozmiar_sredni();
    virtual unsigned int daj_rozmiar_duzy();
    virtual unsigned int daj_male_stoliki();
    virtual unsigned int daj_srednie_stoliki();
    virtual unsigned int daj_duze_stoliki();
    virtual unsigned int daj_czas_symulacji();
    virtual unsigned int daj_liczbe_kelnerow();

    virtual void pobierz_konfiguracje();
    virtual void pobierz_menu();
    virtual void pobierz_linie_konfiguracji();
    virtual void pobierz_linie_menu();

    virtual void sprawdz_konfiguracje();
    virtual void sprawdz_menu();

    virtual void sprawdz_rozmiary();
    virtual void zdefiniuj_blad_konfiguracji();
    virtual void zdefiniuj_blad_menu();

    virtual void przekaz_dania();
    virtual ~ObslugaWejsciowa() = 0;
};


