#include <string>
using std::string;

#include <memory>
using std::unique_ptr;  using std::make_unique;

#include <fstream>
using std::ios; using std::fstream; using std::getline;

#include <random>
#include <chrono>

#include "Symulator.h"
#include "Restauracja.h"
#include "../FunkcjePomocnicze.h"
#include "../Menu/Menu.hpp"


Symulator::Symulator
(
  unsigned int czas_trwania_symulacji,
  string nazwa_pliku_wyjscia,
  string nazwa_restauracji,
  unsigned int rozmiar_maly,
  unsigned int rozmiar_sredni,
  unsigned int rozmiar_duzy,
  unsigned int male,
  unsigned int srednie,
  unsigned int duze,
  unsigned int liczba_kelnerow,
  unique_ptr<Menu> menu
)
{
  restauracja = Restauracja(nazwa_restauracji, nazwa_pliku_wyjscia);
  this -> czas_trwania_symulacji = czas_trwania_symulacji;
  this -> liczba_kelnerow = liczba_kelnerow;
}

void Symulator::rozpocznij_symulacje()
{
  inicjuj_restauracje();
  for (int licznik = 0; licznik < czas_trwania_symulacji; licznik++)
  {
    if (losuj_liczbe() % 5 == 0)
    { losuj_klientow()  ;}
    restauracja.uplyw_czasu();
  }
}

void Symulator::inicjuj_restauracje()
{

  for (int licznik = 1; licznik <= liczba_kelnerow; licznik++)
  { losuj_kelnera(licznik) ;}


}

void Symulator::losuj_klientow()
{
  unsigned int nowi_klienci = losuj_liczbe() % 5;
  while (nowi_klienci != 0)
  {
    losuj_klienta();
    nowi_klienci--;
  }
}

void Symulator::losuj_kelnera(unsigned int identyfikator)
{
  Kelner nowy_kelner(losuj_nazwisko(), identyfikator);
  restauracja.dodaj_kelnera(nowy_kelner);
}

void Symulator::losuj_klienta()
{
  bool dosiada_sie = (losuj_liczbe() % 2)? false: true;
  unique_ptr<Klient> wskaznik_klienta = make_unique<Klient>(losuj_nazwisko(), dosiada_sie);
  restauracja.dodaj_klienta(move(wskaznik_klienta));
}


string Symulator::losuj_nazwisko()
{
  std::fstream plik;
  plik.open("pliki_konfiguracyjne/spis_nazwisk", ios::in);
  if (plik.is_open())
  {
    string nazwisko;
    unsigned int numer_linii = losuj_liczbe() % 96;
    for (int index = 0; index < numer_linii; index++)
    {
      nazwisko.clear();
      getline(plik, nazwisko);
    }
    plik.close();
    return nazwisko;
  }
  else
  { throw  ;} // Dodać wyjatek


}
