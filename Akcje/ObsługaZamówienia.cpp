#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "ObsługaZamówienia.h"
#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "SzkicePotraw.h"

using namespace std;
using SZ = StatusZamowienia;


ObslugaZamowienia::ObslugaZamowienia()
{}

ObslugaZamowienia::ObslugaZamowienia(Stolik& stolik, unique_ptr<Klient> klient, unsigned int numer_zamowienia)
{
  status = SZ::oczekiwanie_na_menu;
  this -> stolik = stolik;
  this -> klienci.push_back(move(klient));
  numer_zamowienia = numer_zamowienia;
}

unsigned int ObslugaZamowienia::daj_numer_zamowienia()
{
  return numer_zamowienia;
}

unsigned int ObslugaZamowienia::daj_ilosc_osob_przy_stoliku()
{
  return (klienci.size());
}

StatusZamowienia ObslugaZamowienia::daj_status()
{
  return status;
}

Stolik ObslugaZamowienia::daj_stolik()
{
  return stolik;
}

Kelner ObslugaZamowienia::daj_kelnera()
{
  return kelner;
}



void ObslugaZamowienia::sprzatnij_ze_stolika()
{
  status = SZ::stol_posprzatany;
}


void ObslugaZamowienia::czekanie_na_zaplate()
{
  status = SZ::czekanie_kelnera_na_zaplate;
}

void ObslugaZamowienia::zakoncz_wszystkie_posilki()
{
  status = SZ::czekanie_na_rachunek;
}

void ObslugaZamowienia::zamow_potrawe(unique_ptr<Danie> nowa_potrawa, unsigned int ilosc_sztuk)
{
  // zamowione_potrawy[nowa_potrawa] = ilosc_sztuk;
  status = SZ::oczekiwanie_na_dania;
}

void ObslugaZamowienia::podaj_dania_do_stolika()
{
  status = SZ::jedzenie;
}

unsigned int ObslugaZamowienia::oblicz_kwote_do_zaplaty()
{
  unsigned int cala_kwota = 0;

  // for (auto& potrawa_i_ich_ilosc:zamowione_potrawy)
  // {
  //     cala_kwota += potrawa_i_ich_ilosc.second * potrawa_i_ich_ilosc.first -> podaj_cene();
  // }

  return cala_kwota;
}


std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie)
{
  switch(zamowienie.daj_status())
  {
    case SZ::oczekiwanie_na_menu:

      return os;

    case SZ::czytanie_menu:
      return os;

    case SZ::oczekiwanie_na_dania:
      return os;

    case SZ::jedzenie:

      return os;

    case SZ::czekanie_na_rachunek:

      return os;

    case SZ::czekanie_kelnera_na_zaplate:

      return os;

    case SZ::zaplacone:

      return os;

    case SZ::wyjscie_z_restauracji:

      return os;

    case SZ::stol_posprzatany:

      return os;

  }
  return os;
}





// void RozwazanieWyboruDan::wykonaj_akcje()
// {
//     cout << "Zastanawianie sie klientow nad wyborem posilkow przy stole "<< obsluga_zamowienia.daj_stolik().daj_numer();
// }

// void PrzyjscieKolejnychOsobDoTegoSamegoStolika::wykonaj_akcje()
// {
//     cout << "Do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " przyszły " << ilosc_kolejnych_osob << " osob. "<<endl;
//     obsluga_zamowienia.dodaj_nowe_osoby(ilosc_kolejnych_osob);
//     cout << "Teraz łącznie przy stoliku jest " << obsluga_zamowienia.daj_ilosc_osob_przy_stoliku();
// }


// void OdebranieZamowieniaOdStolika::wykonaj_akcje()
// {
//     cout << "Kelner " << obsluga_zamowienia.daj_kelnera().daj_imie() << " przyjmuje zamowienie dla stolika numer " << obsluga_zamowienia.daj_stolik().daj_numer();
//     obsluga_zamowienia.zamow_potrawe(potrawa, ilosc_sztuk);
// }



// void CzekanieNaPrzyniesienieDan::wykonaj_akcje()
// {
//     cout<< "Czdkanie na przyniesienie dan przez kelnerad dla stolika nr."<< obsluga_zamowienia.daj_stolik().daj_numer();
// }


// void PodanieDanDoStolika::wykonaj_akcje()
// {
//     cout<< "Dania do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " zostało przyniesionych przez kelnera " << obsluga_zamowienia.daj_kelnera().daj_imie() << "."<<endl;
//     obsluga_zamowienia.podaj_dania_do_stolika();
// }


// void TrwaJedzeniePosilku::wykonaj_akcje()
// {
//     cout<< "Przy stoliku nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " jedzenie posiłku trwa ... czasu";
// }


// void ZakonczenieWszystkichPosilkow::wykonaj_akcje()
// {
//     obsluga_zamowienia.zakoncz_wszystkie_posilki();
//     cout << "Klienci przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer() << "zakonczyli jedzenie posilku";
// }

// void CzekanieNaRachunek::wykonaj_akcje()
// {
//     cout << "Czekanie na rachunek przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer();
// }

// void ZaplataRachunku::wykonaj_akcje()
// {
//     obsluga_zamowienia.zaplac();
//     cout<< "Zamowienie zostalo uregulowane przy stoliku nr. "<<  obsluga_zamowienia.daj_stolik().daj_numer()<<endl;
// }
// void WyjscieZRestauracji::wykonaj_akcje()
// {
//     cout<< "Klienci ze stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " juz wyszli"<< endl;
//     //save do pliku do acrchiwalnych danych
// }

// void PrzygotowanieStoluDlaNowychKlientow::wykonaj_akcje()
// {
//     cout << "Zaczeto sprzatac ze stolika nr." << obsluga_zamowienia.daj_stolik().daj_numer() << endl;
//     obsluga_zamowienia.sprzatnij_ze_stolika();
// }


// vector<Akcja> AkcjeDlaZamowienia::pokaz_dostepne_akcje() // switch dziala jak if
// {
//     switch(aktualne_zamowienie.daj_status())
//     {
//         case SZ::oczekiwanie_na_menu:
//         {
//             return akcje_dla_oczekiwania_na_menu();
//         }
//         case SZ::czytanie_menu:
//         {
//             return akcje_dla_czytania_menu();
//         }
//         case SZ::oczekiwanie_na_dania:
//         {
//             return akcje_dla_oczekiwania_na_dania();
//         }
//         case SZ::jedzenie:
//         {
//             return akcje_dla_jedzenia();
//         }
//         case SZ::czekanie_na_rachunek:
//         {
//             return akcje_dla_czekania_na_rachunek();
//         }
//         case SZ::czekanie_kelnera_na_zaplate:
//         {
//             return akcje_dla_czekania_kelnera_na_zaplate();
//         }
//         case SZ::zaplacone:
//         {
//             return akcje_dla_zaplacenia();
//         }
//         case SZ::wyjscie_z_restauracji:
//         {
//             return akcje_dla_wyjscia_z_restauracji();
//         }
//         case SZ::stol_posprzatany:
//         {
//             return akcje_dla_posprzatanego_stolu();
//         }

//     }
// }
