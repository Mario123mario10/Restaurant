#include "Obsluga_zamowienia.h"
#include "Akcja.h"
#include <vector>
#include "Inne_klasy.h"
#include "Akcje_dla_zamowienia.h"


Akcje_dla_zamowienia::Akcje_dla_zamowienia(Obsluga_zamowienia aktualne_zamowienie)
{
    this -> aktualne_zamowienie = aktualne_zamowienie;
}

vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_oczekiwania_na_menu()
{
    vector <Akcja*> wynikowy;
    Kelner kelner("Jan");
    Akcja_zanies_menu* akcja1 = new Akcja_zanies_menu(aktualne_zamowienie, kelner);
    Przyjscie_kolejnych_osob_do_tego_samego_stolika* akcja2 = new Przyjscie_kolejnych_osob_do_tego_samego_stolika (aktualne_zamowienie, 7);
    wynikowy.push_back(akcja1);
    wynikowy.push_back(akcja2);
    return wynikowy;
}

vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_czytania_menu()
{
    Zupa* z1 = new Zupa(11, "krupnik");
    vector <Akcja*> wynikowy;
    Odebranie_zamowienia_od_stolika* akcja1 = new Odebranie_zamowienia_od_stolika(aktualne_zamowienie, z1, 4);
    Przyjscie_kolejnych_osob_do_tego_samego_stolika* akcja2 = new Przyjscie_kolejnych_osob_do_tego_samego_stolika(aktualne_zamowienie, 9);
    wynikowy.push_back(akcja1);
    wynikowy.push_back(akcja2);
    return wynikowy;
}

vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_oczekiwania_na_dania()
{
    Zupa* z1 = new Zupa(13, "rosol");  // bo akcje są różnych rodzajow i tak samo zupy i inne dania
    vector <Akcja*> wynikowy;

    Odebranie_zamowienia_od_stolika* akcja1 = new Odebranie_zamowienia_od_stolika(aktualne_zamowienie, z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
    Przyjscie_kolejnych_osob_do_tego_samego_stolika* akcja2 = new Przyjscie_kolejnych_osob_do_tego_samego_stolika(aktualne_zamowienie, 9);
    Czekanie_na_przyniesienie_dan* akcja3 = new Czekanie_na_przyniesienie_dan(aktualne_zamowienie);
    Podanie_dan_do_stolika* akcja4 = new Podanie_dan_do_stolika(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    wynikowy.push_back(akcja2);
    wynikowy.push_back(akcja3);
    wynikowy.push_back(akcja4);
    return wynikowy;
}
vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_jedzenia()
{
    vector <Akcja*> wynikowy;

    Zupa* z1 = new Zupa(15, "grochowka");
    Odebranie_zamowienia_od_stolika* akcja1 = new Odebranie_zamowienia_od_stolika(aktualne_zamowienie, z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
    Przyjscie_kolejnych_osob_do_tego_samego_stolika* akcja2 = new Przyjscie_kolejnych_osob_do_tego_samego_stolika(aktualne_zamowienie, 7);
    Trwa_jedzenie_posilku* akcja3 = new Trwa_jedzenie_posilku(aktualne_zamowienie);
    Zakonczenie_wszystkich_posilkow* akcja4 = new Zakonczenie_wszystkich_posilkow(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    wynikowy.push_back(akcja2);
    wynikowy.push_back(akcja3);
    wynikowy.push_back(akcja4);
    return wynikowy;
}
vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_czekania_na_rachunek()
{
    vector <Akcja*> wynikowy;
    Czekanie_na_rachunek* akcja1 = new Czekanie_na_rachunek(aktualne_zamowienie);
    Podanie_rachunku_klientom_przez_kelnera* akcja2 = new Podanie_rachunku_klientom_przez_kelnera(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    wynikowy.push_back(akcja2);
    return wynikowy;

}

vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_czekania_kelnera_na_zaplate()
{
    vector <Akcja*> wynikowy;
    Zaplata_rachunku* akcja1 = new Zaplata_rachunku(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    return wynikowy;

}
vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_zaplacenia()
{
    vector <Akcja*> wynikowy;

    Wyjscie_z_restauracji* akcja1 = new Wyjscie_z_restauracji(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    return wynikowy;
}
vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_wyjscia_z_restauracji()
{
    vector <Akcja*> wynikowy;
    Przygotowanie_stolu_dla_nowych_klientow* akcja1 = new Przygotowanie_stolu_dla_nowych_klientow(aktualne_zamowienie);

    wynikowy.push_back(akcja1);
    return wynikowy;
}
vector<Akcja*> Akcje_dla_zamowienia::akcje_dla_posprzatanego_stolu()
{
    //stol wraca do stolow czystych w klasie restauracja
}




vector<Akcja*> Akcje_dla_zamowienia::pokaz_dostepne_akcje() // switch dziala jak if
{
    switch(aktualne_zamowienie.daj_status())
    {
        case oczekiwanie_na_menu:
        {
            return akcje_dla_oczekiwania_na_menu();
        }
        case czytanie_menu:
        {
            return akcje_dla_czytania_menu();
        }
        case oczekiwanie_na_dania:
        {
            return akcje_dla_oczekiwania_na_dania();
        }
        case jedzenie:
        {
            return akcje_dla_jedzenia();
        }
        case czekanie_na_rachunek:
        {
            return akcje_dla_czekania_na_rachunek();
        }
        case czekanie_kelnera_na_zaplate:
        {
            return akcje_dla_czekania_kelnera_na_zaplate();
        }
        case zaplacone:
        {
            return akcje_dla_zaplacenia();
        }
        case wyjscie_z_restauracji:
        {
            return akcje_dla_wyjscia_z_restauracji();
        }
        case stol_posprzatany:
        {
            return akcje_dla_posprzatanego_stolu();
        }

    }
}
