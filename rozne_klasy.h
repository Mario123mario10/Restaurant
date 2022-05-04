#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>

class Akcje_klienta
{

};
class Akcje_kelnera
{

};

class Kelner
{
    string nazwa;
    vector <Obsluga_zamowienia> trwajace_zamowienia;



};

class Obsluga_zamowienia //zamowienie rozpoczyna sie juz po usiedzeniu przy stoliku
{
    map <Potrawa, unsigned int> zamowione_potrawy; // zamowione potrawy i ich ilosc
    unsigned int ilosc_osob_przy_stoliku;
    unsigned int stolik;
    Status_zamowienia status;

public:
    void dodaj_nowe_osoby(unsigned int nowe_osoby)
    {
        ilosc_osob_przy_stoliku += nowe_osoby;
    }

    void zamow_potrawe(Potrawa nowa_potrawa, unsigned int ilosc_sztuk)
    {
        zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
        status = oczekiwanie_na_dania;
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

};

class Stolik
{
    unsigned int numer;
    unsigned int ilosc_miejsc;
    bool wolny;

};

enum Status_zamowienia // pomyśleć które rzeczy zmienia klient a które kelner
{
    oczekiwanie_na_menu,
    czytanie_menu,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    czekanie_kelnera_na_zaplate,
    zaplacone
};

class Potrawa
{
    unsigned int cena_potrawy;
    string nazwa_potrawy;
public:
    unsigned int podaj_cene()
    {
        return cena_potrawy;
    }
};

class Zupa: public Potrawa
{

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