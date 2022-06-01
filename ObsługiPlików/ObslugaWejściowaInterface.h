#pragma once
#include "ObsługaWejściowa.h"

class InterfejsObslugaWejsciowa
{
public:
    virtual string daj_nazwe_pliku_wyjscia() = 0;
    virtual string daj_nazwe_restauracji() = 0;
    virtual unsigned int daj_rozmiar_maly() = 0;
    virtual unsigned int daj_rozmiar_sredni() = 0;
    virtual unsigned int daj_rozmiar_duzy() = 0;
    virtual unsigned int daj_male_stoliki() = 0;
    virtual unsigned int daj_srednie_stoliki() = 0;
    virtual unsigned int daj_duze_stoliki() = 0;
    virtual unsigned int daj_czas_symulacji() = 0;
    virtual unsigned int daj_liczbe_kelnerow() = 0;

    virtual void pobierz_konfiguracje() = 0;
    virtual void pobierz_menu() = 0;
    virtual void pobierz_linie_konfiguracji() = 0;
    virtual void pobierz_linie_menu() = 0;

    virtual void sprawdz_konfiguracje() = 0;
    virtual void sprawdz_menu() = 0;

    virtual void sprawdz_rozmiary() = 0;
    virtual void zdefiniuj_blad_konfiguracji() = 0;
    virtual void zdefiniuj_blad_menu() = 0;

    virtual void przekaz_dania() = 0;
    virtual ~InterfejsObslugaWejsciowa() = 0;
};


