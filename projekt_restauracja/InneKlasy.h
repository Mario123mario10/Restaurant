
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#include "ObsługaZamówienia.h"

class Potrawa
{
    unsigned int cena_potrawy;
    string nazwa_potrawy;

public:
    Potrawa()
    {}

    Potrawa(unsigned int cena_potrawy, string nazwa_potrawy)
    {
        this -> cena_potrawy = cena_potrawy;
        this -> nazwa_potrawy = nazwa_potrawy
    }

    unsigned int podaj_cene()
    {
        return cena_potrawy;
    }

    string podaj_nazwe()
    {
        return nazwa_potrawy;
    }
};

class Zupa: public Potrawa
{
    string nazwa;
public:
    Zupa(string nazwa)
    {
        this -> nazwa = nazwa;
    }
};
class Deser: public Potrawa
{

};
class Napoj: public Potrawa
{

};
class Drugie_danie: public Potrawa
{

};
class Przystawka: public Potrawa
{

};


enum class StatusZamowienia
{
    oczekiwanie_na_menu,
    czytanie_menu,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    czekanie_kelnera_na_zaplate,
    zaplacone,
    wyjscie_z_restauracji,
    stol_posprzatany
};

class Losowanie
{

};







// class Menu //vector potraw
// {

// };

// int main()
// {
//     Stolik stolik1(1, 5);
// }

class PozycjaRachunku
{
    Potrawa danie;
    unsigned int ilosc_sztuk;
};


class Rachunek:
{
    vector <PozycjaRachunku> lista_produktow;
    unsigned int cena_łączna;
    bool czy_rachunek_zaplacony;
public:
    Rachunek()
    {
        czy_rachunek_zaplacony = false;
    }
    void wyswietl()
    {

    }
    void zaplac()
    {
        czy_rachunek_zaplacony = true;
    }
};
