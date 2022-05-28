#pragma once
#include <vector>
#include <memory>

#include "../ObsługiPlików/ObsługaWyjściowa.h"
#include "../Akcje/ObsługaZamówienia.h"
#include "../Menu/Menu.hpp"
#include "../Klient/Klient.h"
using std::unique_ptr;


class Restauracja
{
    vector <ObslugaZamowienia> zamowienia_aktualne;
    vector <ObslugaZamowienia> zamowienia_zamkniete;
    vector <Kelner> kelnerzy;
    vector <Stolik> stoliki;
    vector <unique_ptr<Klient>> nieobslugiwani_klienci;
    string nazwa;
    Menu menu;
    int dochod;
    ObslugaWyjsciowa wyjscie;

public:
    Restauracja();
    Restauracja(string nazwa, string nazwa_pliku_wyjscia);
    void uplyw_czasu();

    void pokaz_status_kelnerow();
    void pokaz_status_klientow();
    void pokaz_status_zamowien();
    void pokaz_status_stolikow();

    void dodaj_klienta(unique_ptr<Klient> wchodzacy_klient);
    void dodaj_kelnera(Kelner kelner);
    void dodaj_stolik(Stolik stolik);

    void sprawdz_klientow();
    void sprawdz_stoliki();
    void sprawdz_kelnerow();

    void zwolnij_stoliki();
    void zwolnij_kelnerow();
    void zwolnij_zamowienia();

    void stworz_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik);
    void przydziel_klienta();


    void dodaj_zamowienie(unique_ptr<Klient> klient, Stolik& stol);

    // ObslugaZamowienia daj_zamowienie(int index);
    // vector <Stolik> daj_wolne_stoliki();
    // Kelner daj_kelnera(unsigned int index);
    // Menu daj_menu();
    // unsigned int daj_ilosc_aktualnych_zamowien();

};

// void dodaj_zamowienie(ObslugaZamowienia zamowienie);
// void zamknij_zamowienie(ObslugaZamowienia zamowienie);
