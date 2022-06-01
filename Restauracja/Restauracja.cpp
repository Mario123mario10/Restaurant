#include <vector>
#include <iostream>
using std::cout;	using std::endl;

#include "../ObsługaZamówienia/ObsługaZamówienia.h"
#include "Restauracja.h"


Restauracja::Restauracja()
{}

Restauracja::Restauracja(string nazwa, string nazwa_pliku_wyjscia, unique_ptr<Menu> menu)
{
  this -> nazwa = nazwa;
  this -> wyjscie = ObslugaWyjsciowa(nazwa_pliku_wyjscia);
  this -> menu.swap(menu);
}

void Restauracja::uplyw_czasu()
{
  pokaz_wchodzacych_klientow();

  przydziel_klientow();
  posprzataj_klientow();

  sprawdz_zamowienia();
  posprzataj_zamowienia();

  for (ObslugaZamowienia& zam: zamowienia_aktualne)
  {
    zam.uplyw_czasu();
  }

  pokaz_bezczynnych_kelnerow();
  pokaz_nieobslugiwanych_klientow();
  pokaz_wolne_stoliki();
  pokaz_status_zamowien();
}

void Restauracja::pokaz_wchodzacych_klientow()
{
  for (unique_ptr<Klient>& klient: nieobslugiwani_klienci)
  {
    wyjscie << *klient << " wszedł do restauracji" <<  "\n";
  }
}

void Restauracja::pokaz_bezczynnych_kelnerow()
{
  for (unique_ptr<Kelner>& kelner: wolni_kelnerzy)
  {
    wyjscie << *kelner << " nie obsługuje zamówienia" << "\n";
  }
}

void Restauracja::pokaz_nieobslugiwanych_klientow()
{
  for (unique_ptr<Klient>& klient: nieobslugiwani_klienci)
  {
    wyjscie << *klient << " nie jest obsługiwany" <<  "\n";
  }
}

void Restauracja::pokaz_status_zamowien()
{
  for (ObslugaZamowienia& zamowienie: zamowienia_aktualne)
  {
    wyjscie << zamowienie;
    wyjscie << "\n";
  }
}

void Restauracja::pokaz_wolne_stoliki()
{
  for (unique_ptr<Stolik>& stolik: wolne_stoliki)
  {
    wyjscie << *stolik << " jest wolny" << "\n";
  }
}

void Restauracja::dodaj_klienta(unique_ptr<Klient> wchodzacy_klient)
{
  nieobslugiwani_klienci.push_back(move(wchodzacy_klient));
}

void Restauracja::dodaj_kelnera(unique_ptr<Kelner> kelner)
{
  this -> wolni_kelnerzy.push_back(move(kelner));
}

void Restauracja::dodaj_stolik(unique_ptr<Stolik> stolik)
{
  this -> wolne_stoliki.push_back(move(stolik));
}

void Restauracja::dodaj_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik)
{
  zamowienia_aktualne.push_back(ObslugaZamowienia(move(stolik), move(klient)));
}

void Restauracja::przydziel_klientow()
{
  for (unique_ptr<Klient>& klient: nieobslugiwani_klienci)
  {
    for (ObslugaZamowienia& zamowienie: zamowienia_aktualne)
    {
      if (
        (not (zamowienie.dla_czekajacych() xor klient -> czy_dosiada_sie())) and (zamowienie.daj_status() < SZ::jedzenie)
      )
      {
        unique_ptr<Klient> wsk;
        wsk.swap(klient);
        zamowienie.dodaj_klienta(move(wsk));
      }
    }
  }
}

void Restauracja::posprzataj_klientow()
{
  for (int index = 0; index < nieobslugiwani_klienci.size(); index++)
  {
    if (nieobslugiwani_klienci[index] == nullptr)
    {
      nieobslugiwani_klienci.erase(nieobslugiwani_klienci.begin() + index);
      posprzataj_klientow();
      return;
    }
  }
}

void Restauracja::posprzataj_zamowienia()
{
  for (int index = 0; index < zamowienia_aktualne.size(); index++)
  {
    if ((zamowienia_aktualne[index].daj_status() == SZ::koniec) and (not zamowienia_aktualne[index].przydzielony_kelner()))
    {
      zamowienia_aktualne.erase(zamowienia_aktualne.begin() + index);
      posprzataj_zamowienia();
      return;
    }
  }
}


void Restauracja::sprawdz_zamowienia()
{
  for (ObslugaZamowienia& zamowienie: zamowienia_aktualne)
  {
    unique_ptr<Kelner> kelner;
    unique_ptr<Stolik> stolik;
    unique_ptr<Danie> przystawka;
    unique_ptr<Danie> danie_glowne;
    unique_ptr<Danie> deser;
    unique_ptr<Danie> napoj;

    switch (zamowienie.daj_status())
    {
    case (SZ::oczekiwanie_na_menu):
    case (SZ::czekanie_na_rachunek):
    case (SZ::przyniesienie_dan):
      if (( not zamowienie.przydzielony_kelner()) and (not wolni_kelnerzy.empty()))
      {
        zamowienie.przydziel_kelnera(move(przekaz_kelnera()));
      }
      break;

    case (SZ::zamawianie_dan):
      przystawka = menu -> wybierz_przystawke();
      danie_glowne = menu -> wybierz_danie_glowne();
      deser = menu -> wybierz_deser();
      napoj = menu -> wybierz_napoj();
      zamowienie.zamow_potrawe(move(przystawka));
      zamowienie.zamow_potrawe(move(danie_glowne));
      zamowienie.zamow_potrawe(move(deser));
      zamowienie.zamow_potrawe(move(napoj));
      zamowienie.zamowiono();
      break;


    case (SZ::oczekiwanie_na_dania):
    case (SZ::jedzenie):
      if (zamowienie.przydzielony_kelner())
      {
        kelner = zamowienie.zwolnij_kelnera();
        wolni_kelnerzy.push_back(move(kelner));
      }
      break;
    case (SZ::placenie):
      przychod += zamowienie.oblicz_kwote_do_zaplaty();
      break;

    case (SZ::koniec):
      kelner = zamowienie.zwolnij_kelnera();
      stolik = zamowienie.zwolnij_stolik();
      wolni_kelnerzy.push_back(move(kelner));
      wolne_stoliki.push_back(move(stolik));
      break;

    default:
      break;
    }
  }

}
    // oczekiwanie_na_menu,   przydzielić kelnera   +++++++
    // zamawianie_dan,        utworzyć dania        +++++++
    // oczekiwanie_na_dania,  zwolnić kelnera       +++++++
    // przyniesienie_dan,     przypisać kelnera     +++++++
    // jedzenie,              zwolnić_kelnera       +++++++
    // czekanie_na_rachunek,  przypisać kelnera     +++++++
    // placenie,
    // wyjscie_z_restauracji,
    // sprzatanie_stolika,
    // koniec                 zwolnić kelnera,      +++++++
    //                        zwolnić stolik        +++++++


unique_ptr<Kelner> Restauracja::przekaz_kelnera()
{
  if (not wolni_kelnerzy.empty())
  {
    unique_ptr<Kelner> kelner;
    wolni_kelnerzy[wolni_kelnerzy.size() - 1].swap(kelner);
    wolni_kelnerzy.pop_back();
    return kelner;
  }
  return nullptr;
}


unsigned int Restauracja::daj_ilosc_aktualnych_zamowien()
{
  return zamowienia_aktualne.size();
}

void Restauracja::aktywuj_obslugi_zamowien()
{
  for (ObslugaZamowienia& zamowienie: zamowienia_aktualne)
  {
    zamowienie.uplyw_czasu();
  }
}
