#pragma once
#include "Obsluga_zamowienia.h"
//#include "Obsluga_wejsciowa.h"
#include <vector>
#include "Menu.h"

class Restauracja
{
    vector <Obsluga_zamowienia> zamowienia_aktualne;
    vector <Obsluga_zamowienia> zamowienia_zamkniete;
    vector <Kelner> kelnerzy;
    vector <Stolik> stoliki;
    Menu menu;

public:
    Restauracja();

    void dodaj_zamowienie(Obsluga_zamowienia zamowienie);

    void zamknij_zamowienie(Obsluga_zamowienia zamowienie);

    Obsluga_zamowienia daj_zamowienie(int index);

    vector <Stolik> daj_wolne_stoliki();

    Kelner daj_kelnera(unsigned int index);

    Danie* daj_potrawe(unsigned int numer);  // wszystko co ma rodzaje i ma podklasy ma wskaźniki

    Menu daj_menu();

    unsigned int daj_ilosc_aktualnych_zamowien();

};





// class Czytanie_plikow
// {
//     Konfiguracja konfiguracja;
// public:
//     Czytanie_plikow(Konfiguracja konfiguracja)
//     {
//         this -> konfiguracja = konfiguracja;
//     }

//     vector <Kelner> czytaj_plik_kelnerow()
//     {

//     }
//     vector <Stolik> czytaj_plik_stoliki()
//     {

//     }
//     Menu czytaj_plik_menu()
//     {

//     }
// };

// class Konfiguracja  // plikow bedzie kazdego rodzaju 1
// {
//     string plik_menu;
//     string plik_kelnerzy;
//     string plik_stoliki;
// public:
//     Konfiguracja()
//     {
//         plik_menu = "menu.txt";
//         plik_kelnerzy = "kelnerzy.txt";
//         plik_stoliki = "stoliki.txt";
//     }

// };

