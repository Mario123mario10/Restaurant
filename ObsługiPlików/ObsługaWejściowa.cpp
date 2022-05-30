#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ios; using std::fstream; using std::getline;
#include <iostream>
using std::cout;	using std::cerr;  using std::endl;
#include <regex>
using std::regex;  using std::smatch; using std::regex_search;  using std::regex_match;
#include <memory>
using std::unique_ptr; using std::make_unique;

using std::move;
using std::stoul;

#include "ObsługaWejściowa.h"
#include "../Błędy.h"
#include "../Stałe.h"
#include "../Dania/poddania/ZimneNapoje.hpp"
#include "../Dania/poddania/CiepłeNapoje.hpp"
#include "../Dania/poddania/DanieMięsne.hpp"
#include "../Dania/poddania/DanieWegetariańskie.hpp"
#include "../Dania/poddania/Deser.hpp"
#include "../Dania/poddania/Przystawka.hpp"
#include "../Dania/poddania/Zupa.hpp"


ObslugaWejsciowa::ObslugaWejsciowa(string sciezka)
{
  nazwa_pliku_wyjscia = "";
  sciezka_menu = "";
  sciezka_do_nazwisk = "";
  nazwa_restauracji = "";
  rozmiar_maly = 0;
  rozmiar_sredni = 0;
  rozmiar_duzy = 0;
  male = 0;
  srednie = 0;
  duze = 0;
  czas_trwania_symulacji = 0;
  liczba_kelnerow = 0;
  czas_raportowania = 0;
  sciezka_konfiguracyjna = sciezka;
  pobierz_konfiguracje();
  pobierz_menu();
}

void ObslugaWejsciowa::pobierz_konfiguracje()
{
  plik_konfiguracyjny.open(sciezka_konfiguracyjna, ios::in);
  if (plik_konfiguracyjny.is_open())
  {
    while (not plik_konfiguracyjny.eof())
    { pobierz_linie_konfiguracji() ;}
    plik_konfiguracyjny.close();
    sprawdz_konfiguracje();
  }
  else
  { throw NieZnalezionoPliku(sciezka_konfiguracyjna) ;}

}


void ObslugaWejsciowa::pobierz_menu()
{
  plik_menu.open(sciezka_menu, ios::in);
  if (plik_menu.is_open())
  {
    while (not plik_menu.eof())
    { pobierz_linie_menu() ;}
    plik_menu.close();
    sprawdz_menu();
  }
  else
  { throw NieZnalezionoPliku(sciezka_menu) ;}
}


void ObslugaWejsciowa::pobierz_linie_menu()
{
  string linia;
  smatch przechwycone;
  getline(plik_menu, linia);
  if (regex_match(linia, przechwycone, L_M_PRZYSTAWKA))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<Przystawka> przystawka = make_unique<Przystawka>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  else if (regex_match(linia, przechwycone, L_M_ZUPA))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<Zupa> przystawka = make_unique<Zupa>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  else if (regex_match(linia, przechwycone, L_M_DANIE_MIESNE))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<DanieMiesne> przystawka = make_unique<DanieMiesne>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }
  else if (regex_match(linia, przechwycone, L_M_DANIE_WEGE))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<DanieWegetarianskie> przystawka = make_unique<DanieWegetarianskie>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  else if (regex_match(linia, przechwycone, L_M_DESER))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<Deser> przystawka = make_unique<Deser>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  else if (regex_match(linia, przechwycone, L_M_NAPOJ_CIEPLY))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<CieplyNapoj> przystawka = make_unique<CieplyNapoj>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  else if (regex_match(linia, przechwycone, L_M_NAPOJ_ZIMNY))
  {
    string nazwa = przechwycone[1];
    unsigned int zlote = stoul(przechwycone[2]);
    unsigned int grosze = stoul(przechwycone[3]);
    if (nazwa.empty())
    { throw NiepoprawnaNazwa(nazwa) ;}
    else if (zlote == 0 and grosze == 0)
    { throw NiepoprawnyKoszt(Kwota(zlote, grosze)) ;}
    unique_ptr<ZimnyNapoj> przystawka = make_unique<ZimnyNapoj>(nazwa, Kwota(zlote, grosze));
    menu.dodaj_danie(move(przystawka));
  }

  linia.clear();
}

void ObslugaWejsciowa::pobierz_linie_konfiguracji()
{
  string linia;
  smatch przechwycone;
  getline(plik_konfiguracyjny, linia);
  if (regex_match(linia, przechwycone, L_NAZWA_RESTAURACJI))
  { nazwa_restauracji = przechwycone[1] ;}

  else if (regex_match(linia, przechwycone, L_NAZWA_PLIKU_WYJSCIA))
  { nazwa_pliku_wyjscia = przechwycone[1] ;}

  else if (regex_match(linia, przechwycone, L_CZAS_TRWANIA))
  { czas_trwania_symulacji = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_CZAS_RAPORTOWANIA))
  { czas_raportowania = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_R_MALYCH_STOLIKOW))
  { rozmiar_maly = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_R_SREDNICH_STOLIKOW))
  { rozmiar_sredni = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_R_DUZYCH_STOLIKOW))
  { rozmiar_duzy = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_L_MALYCH_STOLIKOW))
  { male = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_L_SREDNICH_STOLIKOW))
  { srednie = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_L_DUZYCH_STOLIKOW))
  { duze = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_L_KELNEROW))
  { liczba_kelnerow = stoul(przechwycone[1]) ;}

  else if (regex_match(linia, przechwycone, L_NAZWA_PLIKU_MENU))
  { sciezka_menu = przechwycone[1] ;}

  linia.clear();
}




void ObslugaWejsciowa::sprawdz_konfiguracje()
{
  if
  (
    ( not nazwa_restauracji.empty() )
    and ( not nazwa_pliku_wyjscia.empty() )
    and ( not sciezka_menu.empty() )
    and rozmiar_duzy
    and rozmiar_sredni
    and rozmiar_maly
    and male
    and srednie
    and duze
    and czas_trwania_symulacji
    and liczba_kelnerow
    and czas_raportowania
  )
  { sprawdz_rozmiary()  ;}
  else
  { zdefiniuj_blad_konfiguracji() ;}
}

void ObslugaWejsciowa::zdefiniuj_blad_konfiguracji()
{
  string komunikat = "| Brakuje następujących danych: ";
  komunikat.clear();

  if (rozmiar_duzy)
  { komunikat += "rozmiaru dużych stolików | ";}

  if (rozmiar_maly)
  { komunikat += "rozmiaru małych stolików | ";}

  if (rozmiar_sredni)
  { komunikat += "rozmiaru średnich stolików | ";}

  if (male)
  { komunikat += "liczby małych stolików | ";}

  if (srednie)
  { komunikat += "liczby średnich stolików | ";}

  if (duze)
  { komunikat += "liczby małych stolików | ";}

  if (czas_trwania_symulacji)
  { komunikat += "czasu trwania symulacji | ";}

  if ( not nazwa_restauracji.empty() )
  { komunikat += "nazwy restauracji | ";}

  if ( not nazwa_pliku_wyjscia.empty() )
  { komunikat += "nazwy pliku wyjścia | ";}

  if ( not sciezka_menu.empty() )
  { komunikat += "ścieżki do menu | ";}

  if ( not sciezka_do_nazwisk.empty() )
  { komunikat += "ścieżki do nazwisk | ";}


  if (liczba_kelnerow)
  { komunikat += "liczby kelnerów | ";}

  if (czas_raportowania)
  { komunikat += "czasu raportowania | ";}

  throw NiepelnaKonfiguracja(komunikat);
}
void ObslugaWejsciowa::sprawdz_menu()
{
  if (menu.czy_poprawne())
  { return; }
  else
  { throw NieprawidloweMenu("Menu musi posiadać przynajmniej po jednej potrawie z każdej kategorii");}
}

void ObslugaWejsciowa::sprawdz_rozmiary()
{
  if ((rozmiar_duzy <= rozmiar_sredni) or (rozmiar_sredni <= rozmiar_maly))
  { throw NieprawidloweRozmiary(rozmiar_maly, rozmiar_sredni, rozmiar_duzy) ;}
}

string ObslugaWejsciowa::daj_nazwe_pliku_wyjscia()
{ return nazwa_pliku_wyjscia ;}

string ObslugaWejsciowa::daj_sciezke_do_nazwisk()
{ return sciezka_do_nazwisk ;}

string ObslugaWejsciowa::daj_nazwe_restauracji()
{ return nazwa_restauracji ;}

unsigned int ObslugaWejsciowa::daj_rozmiar_maly()
{ return rozmiar_maly ;}

unsigned int ObslugaWejsciowa::daj_rozmiar_sredni()
{ return rozmiar_sredni ;}

unsigned int ObslugaWejsciowa::daj_rozmiar_duzy()
{ return rozmiar_duzy ;}

unsigned int ObslugaWejsciowa::daj_male_stoliki()
{ return male ;}

unsigned int ObslugaWejsciowa::daj_srednie_stoliki()
{ return srednie ;}

unsigned int ObslugaWejsciowa::daj_duze_stoliki()
{ return duze ;}

unsigned int ObslugaWejsciowa::daj_czas_symulacji()
{ return czas_trwania_symulacji ;}

unsigned int ObslugaWejsciowa::daj_liczbe_kelnerow()
{ return liczba_kelnerow ;}

unsigned int ObslugaWejsciowa::daj_czas_raportowania()
{ return czas_raportowania ;}

