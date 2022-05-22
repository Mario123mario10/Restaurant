#include "Obsluga_zamowienia.h"
#include "Akcje.h"
#include <vector>
#include "Inne_klasy.h"


class Akcje_dla_zamowienia  //ta klasa ma ustalac kolejne mozliwe statusy zamowienia
{
   Obsluga_zamowienia aktualne_zamowienie;

public:
    Akcje_dla_zamowienia(Obsluga_zamowienia aktualne_zamowienie)
    {
        this -> aktualne_zamowienie = aktualne_zamowienie;
    }

    vector<Akcja> akcje_dla_oczekiwania_na_menu()
    {
        vector <Akcja> wynikowy;
        Kelner kelner("Jan");
        Akcja_zanies_menu akcja1(aktualne_zamowienie, kelner);
        Przyjscie_kolejnych_osob_do_tego_samego_stolika akcja2(aktualne_zamowienie, 7);
        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;
    }

    vector<Akcja> akcje_dla_czytania_menu()
    {
        Zupa z1("krupnik");
        vector <Akcja> wynikowy;
        Odebranie_zamowienia_od_stolika akcja1(aktualne_zamowienie, &z1, 4);
        Przyjscie_kolejnych_osob_do_tego_samego_stolika akcja2(aktualne_zamowienie, 9);
        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;
    }

    vector<Akcja> akcje_dla_oczekiwania_na_dania()
    {
        Zupa z1("rosol");
        vector <Akcja> wynikowy;

        Odebranie_zamowienia_od_stolika akcja1(aktualne_zamowienie, &z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
        Przyjscie_kolejnych_osob_do_tego_samego_stolika akcja2(aktualne_zamowienie, 9);
        Czekanie_na_przyniesienie_dan akcja3(aktualne_zamowienie);
        Podanie_dan_do_stolika akcja4(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        wynikowy.push_back(akcja3);
        wynikowy.push_back(akcja4);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_jedzenia()
    {
        vector <Akcja> wynikowy;

        Zupa z1("grochowka");
        Odebranie_zamowienia_od_stolika akcja1(aktualne_zamowienie, &z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
        Przyjscie_kolejnych_osob_do_tego_samego_stolika akcja2(aktualne_zamowienie, 7);
        Trwa_jedzenie_posilku akcja3(aktualne_zamowienie);
        Zakonczenie_wszystkich_posilkow akcja4(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        wynikowy.push_back(akcja3);
        wynikowy.push_back(akcja4);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_czekania_na_rachunek()
    {
        vector <Akcja> wynikowy;
        Czekanie_na_rachunek akcja1(aktualne_zamowienie);
        Podanie_rachunku_klientom_przez_kelnera akcja2(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;

    }

    vector<Akcja> akcje_dla_czekania_kelnera_na_zaplate()
    {
        vector <Akcja> wynikowy;
        Zaplata_rachunku akcja1(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        return wynikowy;

    }
    vector<Akcja> akcje_dla_zaplacenia()
    {
        vector <Akcja> wynikowy;

        Wyjscie_z_restauracji akcja1(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_wyjscia_z_restauracji()
    {
        vector <Akcja> wynikowy;
        Przygotowanie_stolu_dla_nowych_klientow akcja1(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_posprzatanego_stolu()
    {
        //stol wraca do stolow czystych w klasie restauracja
    }




    vector<Akcja> pokaz_dostepne_akcje() // switch dziala jak if
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
};
