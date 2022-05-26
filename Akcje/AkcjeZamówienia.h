#include <vector>
#include "ObsługaZamówienia.h"
#include "Akcja.h"
#include "InneKlasy.h"


class Akcje_dla_zamowienia  //ta klasa ma ustalac kolejne mozliwe statusy zamowienia
{
   ObslugaZamowienia aktualne_zamowienie;

public:
    Akcje_dla_zamowienia(ObslugaZamowienia aktualne_zamowienie)
    {
        this -> aktualne_zamowienie = aktualne_zamowienie;
    }

    vector<Akcja> akcje_dla_oczekiwania_na_menu()
    {
        vector <Akcja> wynikowy;
        Kelner kelner("Jan");
        Akcja_zanies_menu akcja1(aktualne_zamowienie, kelner);
        PrzyjscieKolejnychOsobDoTegoSamegoStolika akcja2(aktualne_zamowienie, 7);
        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_czytania_menu()
    {
        ZupaSzkic z1("krupnik");
        vector <Akcja> wynikowy;
        OdebranieZamowieniaOdStolika akcja1(aktualne_zamowienie, &z1, 4);
        PrzyjscieKolejnychOsobDoTegoSamegoStolika akcja2(aktualne_zamowienie, 9);
        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;
    }

    vector<Akcja> akcje_dla_oczekiwania_na_dania()
    {
        ZupaSzkic z1("rosol");
        vector <Akcja> wynikowy;

        OdebranieZamowieniaOdStolika akcja1(aktualne_zamowienie, &z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
        PrzyjscieKolejnychOsobDoTegoSamegoStolika akcja2(aktualne_zamowienie, 9);
        CzekanieNaPrzyniesienieDan akcja3(aktualne_zamowienie);
        PodanieDanDoStolika akcja4(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        wynikowy.push_back(akcja3);
        wynikowy.push_back(akcja4);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_jedzenia()
    {
        vector <Akcja> wynikowy;

        ZupaSzkic z1("grochowka");
        OdebranieZamowieniaOdStolika akcja1(aktualne_zamowienie, &z1, 2); // moze po zamowieniu jeszcze raz zamawiac posilki zeb restauracja wiecej zarobila
        PrzyjscieKolejnychOsobDoTegoSamegoStolika akcja2(aktualne_zamowienie, 7);
        TrwaJedzeniePosilku akcja3(aktualne_zamowienie);
        ZakonczenieWszystkichPosilkow akcja4(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        wynikowy.push_back(akcja3);
        wynikowy.push_back(akcja4);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_czekania_na_rachunek()
    {
        vector <Akcja> wynikowy;
        CzekanieNaRachunek akcja1(aktualne_zamowienie);
        PodanieRachunkuKlientomPrzezKelnera akcja2(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        wynikowy.push_back(akcja2);
        return wynikowy;

    }

    vector<Akcja> akcje_dla_czekania_kelnera_na_zaplate()
    {
        vector <Akcja> wynikowy;
        ZaplataRachunku akcja1(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        return wynikowy;

    }
    vector<Akcja> akcje_dla_zaplacenia()
    {
        vector <Akcja> wynikowy;

        WyjscieZRestauracji akcja1(aktualne_zamowienie);

        wynikowy.push_back(akcja1);
        return wynikowy;
    }
    vector<Akcja> akcje_dla_wyjscia_z_restauracji()
    {
        vector <Akcja> wynikowy;
        PrzygotowanieStoluDlaNowychKlientow akcja1(aktualne_zamowienie);

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
