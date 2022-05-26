#include <vector>

#include "../Akcje/ObsługaZamówienia.h"
#include "Restauracja.h"


Restauracja::Restauracja()
{
    menu = czytanie.czytaj_plik_menu();
    kelnerzy = czytanie.czytaj_plik_kelnerow();
    stoliki = czytanie.czytaj_plik_stoliki();

}

void Restauracja::dodaj_zamowienie(ObslugaZamowienia zamowienie)
{
    zamowienia_aktualne.push_back(zamowienie);
}

void Restauracja::zamknij_zamowienie(ObslugaZamowienia zamowienie)
{
    zamowienia_aktualne.erase(zamowienia_aktualne.index(zamowienie));
    zamowienia_zamkniete.push_back(zamowienie);
}

ObslugaZamowienia Restauracja::daj_zamowienie(int index)
{
    return zamowienia_aktualne[index];

}
vector <Stolik> Restauracja::daj_wolne_stoliki()
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

Kelner Restauracja::daj_kelnera(unsigned int index)
{
    return kelnerzy[index];
}

Danie* Restauracja::daj_potrawe(unsigned int numer)  // wszystko co ma rodzaje i ma podklasy ma wskaźniki
{
    return menu.daj_potrawe();
}

Menu Restauracja::daj_menu()
{
    return menu;
}
unsigned int Restauracja::daj_ilosc_aktualnych_zamowien()
{
    return zamowienia_aktualne.size();
}
