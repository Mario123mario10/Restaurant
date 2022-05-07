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

#include "BłędyWejścia.h"
#include "ObsługaWejściowa.h"

const extern regex L_NAZWA_PLIKU_WYJSCIA;
const extern regex L_NAZWA_RESTAURACJI;
const extern regex L_CZAS_TRWANIA;
const extern regex L_CZAS_RAPORTOWANIA;
const extern regex L_R_MALYCH_STOLIKOW;
const extern regex L_R_SREDNICH_STOLIKOW;
const extern regex L_R_DUZYCH_STOLIKOW;
const extern regex L_L_MALYCH_STOLIKOW;
const extern regex L_L_SREDNICH_STOLIKOW;
const extern regex L_L_DUZYCH_STOLIKOW;
const extern regex L_L_KELNEROW;
const extern regex L_L_KUCHARZY;



ObslugaWejsciowa::ObslugaWejsciowa(string sciezka)
{
  nazwa_pliku_wyjscia = "";
  nazwa_restauracji = "";
  rozmiar_maly = 0;
  rozmiar_sredni = 0;
  rozmiar_duzy = 0;
  male = 0;
  srednie = 0;
  duze = 0;
  czas_trwania_symulacji = 0;
  liczba_kelnerow = 0;
  liczba_kucharzy = 0;

  plik.open(sciezka, ios::in);
  if (plik.is_open())
  {
    while (not plik.eof())
    { pobierz_linie() ;}
    plik.close();
    sprawdz_dane();
  }
  else
  { throw NieZnalezionoPliku(sciezka) ;}
}

void ObslugaWejsciowa::pobierz_linie()
{
  string linia;
  smatch przechwycone;
  getline(plik, linia);
  if (regex_match(linia, przechwycone, L_NAZWA_RESTAURACJI))
  { nazwa_restauracji = przechwycone[1] ;}

  else if (regex_match(linia, przechwycone, L_NAZWA_PLIKU_WYJSCIA))
  { nazwa_pliku_wyjscia = przechwycone[1] ;}

  else if (regex_match(linia, przechwycone, L_CZAS_TRWANIA))
  { czas_trwania_symulacji = stoul(przechwycone[1]) ;}

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

  else if (regex_match(linia, przechwycone, L_L_KUCHARZY))
  { liczba_kucharzy = stoul(przechwycone[1]) ;}

  linia.clear();
}

void ObslugaWejsciowa::sprawdz_dane()
{
  if
  (
    not(
      ( not nazwa_restauracji.empty() )
      and ( not nazwa_pliku_wyjscia.empty() )
      and rozmiar_duzy
      and rozmiar_sredni
      and rozmiar_maly
      and male
      and srednie
      and duze
      and czas_trwania_symulacji
      and liczba_kelnerow
      and liczba_kucharzy
    )
  )
  { zdefiniuj_blad() ;}
}

void ObslugaWejsciowa::zdefiniuj_blad()
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

  if (liczba_kelnerow)
  { komunikat += "liczby kelnerów | ";}

  if (liczba_kucharzy)
  { komunikat += "liczby kucharzy | ";}

  throw NieprawidlowaKonfiguracja(komunikat);
}

string ObslugaWejsciowa::daj_nazwe_pliku_wyjscia()
{ return nazwa_pliku_wyjscia ;}

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

unsigned int ObslugaWejsciowa::daj_liczbe_kucharzy()
{ return liczba_kucharzy ;}

unsigned int ObslugaWejsciowa::daj_liczbe_kelnerow()
{ return liczba_kucharzy ;}
