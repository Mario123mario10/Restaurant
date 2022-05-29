#pragma once
#include <vector>
#include <memory>

#include "../ObsługiPlików/ObsługaWyjściowa.h"
#include "../ObsługaZamówienia/ObsługaZamówienia.h"
#include "../Menu/Menu.hpp"
#include "../Klient/Klient.h"
using std::unique_ptr;


class Restauracja
{
    vector <ObslugaZamowienia> zamowienia_aktualne;
    vector <ObslugaZamowienia> zamowienia_zamkniete;
    vector <unique_ptr<Kelner>> wolni_kelnerzy;
    vector <unique_ptr<Stolik>> wolne_stoliki;
    vector <unique_ptr<Klient>> nieobslugiwani_klienci;
    string nazwa;
    unique_ptr<Menu> menu;
    int przychod;
    ObslugaWyjsciowa wyjscie;

public:
    Restauracja();
    Restauracja(string nazwa, string nazwa_pliku_wyjscia, unique_ptr<Menu> menu);
    void uplyw_czasu();

    void pokaz_status_kelnerow();
    void pokaz_status_zamowien();
    void pokaz_status_stolikow();
    void pokaz_status_klientow();
    void pokaz_wchodzacych_klientow();

    void dodaj_klienta(unique_ptr<Klient> wchodzacy_klient);
    void dodaj_kelnera(unique_ptr<Kelner> kelner);
    void dodaj_stolik(unique_ptr<Stolik> stolik);
    void dodaj_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik);

    void sprawdz_klientow();
    void sprawdz_kelnerow();
    void sprawdz_zamowienia();

    // void zwolnij_stoliki();
    // void zwolnij_kelnerow();
    void zwolnij_zamowienia();

    unique_ptr<Kelner> przekaz_kelnera();


    unsigned int daj_ilosc_aktualnych_zamowien();

};

