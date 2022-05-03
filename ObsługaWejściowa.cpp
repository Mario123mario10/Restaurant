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


const extern regex L_NAZWA_RESTAURACJI;
const extern regex L_CZAS_TRWANIA;
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
  sciezka.empty();
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

  // else if (regex_match(linia, przechwycone, L_L_MALYCH_STOLIKOW))
  // {

  // }
  // else if (regex_match(linia, przechwycone, L_L_MALYCH_STOLIKOW))
  // {

  // }
  // else if (regex_match(linia, przechwycone, L_L_MALYCH_STOLIKOW))
  // {

  // }
  // else if (regex_match(linia, przechwycone, L_L_MALYCH_STOLIKOW))
  // {

  // }
  linia.clear();
}

void ObslugaWejsciowa::sprawdz_dane()
{
  if
  (
    rozmiar_duzy
    and rozmiar_sredni
    and rozmiar_maly
    and male
    and srednie
    and duze
    and czas_trwania_symulacji
    and ( not nazwa_restauracji.empty() )
  )
  {
    Restauracja
    (
      nazwa_restauracji,
      rozmiar_maly,
      rozmiar_sredni,
      rozmiar_duzy,
      male,
      srednie,
      duze
    );
  }
  else
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
  throw NieprawidlowaKonfiguracja(komunikat);
}

