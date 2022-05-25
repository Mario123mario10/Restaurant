#include "InneKlasy.h"
#include <vector>

class Restauracja
{
    vector <ObslugaZamowienia> zamowienia_aktualne;
    vector <ObslugaZamowienia> zamowienia_zamkniete;
    vector <Kelner> kelnerzy;
    vector <Stolik> stoliki;
    int dochod;
    Menu menu;

public:
    Restauracja()
    {
        Konfiguracja konf;
        Czytanie_plikow czytanie(konf);
        menu = czytanie.czytaj_plik_menu();
        kelnerzy = czytanie.czytaj_plik_kelnerow();
        stoliki = czytanie.czytaj_plik_stoliki();

    }

    void dodaj_zamowienie(ObslugaZamowienia zamowienie)
    {
        zamowienia_aktualne.push_back(zamowienie);
    }

    void zamknij_zamowienie(ObslugaZamowienia zamowienie)
    {
        zamowienia_aktualne.erase(zamowienia_aktualne.index(zamowienie));
        zamowienia_zamkniete.push_back(zamowienie);
    }

    ObslugaZamowienia daj_zamowienie(int index)
    {
        return zamowienia_aktualne[index];

    }
    vector <Stolik> daj_wolne_stoliki()
    {
        vector <Stolik> wolne_stoliki;
        for (const Stolik& stolik:stoliki)
        {
            if (stolik.czy_wolny() == true)
            {
                wolne_stoliki.push_back(stolik);
            }
        }
        return wolne_stoliki;
    }

    Kelner daj_kelnera(unsigned int index)
    {
        return kelnerzy[index];
    }

    Danie* daj_potrawe(unsigned int numer)  // wszystko co ma rodzaje i ma podklasy ma wskaźniki
    {
        return menu.daj_potrawe();
    }

    Menu daj_menu()
    {
        return menu;
    }
    unsigned int daj_ilosc_aktualnych_zamowien()
    {
        return zamowienia_aktualne.size();
    }

};

class Czytanie_plikow
{
    Konfiguracja konfiguracja;
public:
    Czytanie_plikow(Konfiguracja konfiguracja)
    {
        this -> konfiguracja = konfiguracja;
    }

    vector <Kelner> czytaj_plik_kelnerow()
    {

    }
    vector <Stolik> czytaj_plik_stoliki()
    {

    }
    Menu czytaj_plik_menu()
    {

    }
};

class Konfiguracja  // plikow bedzie kazdego rodzaju 1
{
    string plik_menu;
    string plik_kelnerzy;
    string plik_stoliki;
public:
    Konfiguracja()
    {
        plik_menu = "menu.txt";
        plik_kelnerzy = "kelnerzy.txt";
        plik_stoliki = "stoliki.txt";
    }

};

