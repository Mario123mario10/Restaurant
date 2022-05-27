#include <string>
using std::string;

#include <memory>
using std::unique_ptr;  using std::make_unique;

#include <random>
#include <chrono>

#include "Symulator.h"
#include "RestauracjaSzkic.h"
#include "Restauracja.h"
#include "../FunkcjePomocnicze.h"
#include "../Menu/Menu.hpp"

unsigned int losuj_liczbe()
{
  unsigned int nasiono = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(nasiono);
  return generator();
};

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
  unsigned int liczba_kucharzy,
  unsigned int liczba_kelnerow,
  unique_ptr<Menu> menu
)
{
  restauracja = Restauracja(nazwa_restauracji, nazwa_pliku_wyjscia);
  this -> czas_trwania_symulacji = czas_trwania_symulacji;
  this -> liczba_kelnerow = liczba_kelnerow;
  this -> liczba_kucharzy = liczba_kucharzy;
  this -> licznik_potraw; // wyszczególnić

}

void Symulator::rozpocznij_symulacje()
{
  inicjuj_restauracje();
  for (int licznik = 0; licznik < czas_trwania_symulacji; licznik++)
  {
    if (losuj_liczbe() % 2 == 0)
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
  unsigned int nowi_klienci = losuj_liczbe() % 3;
  while (nowi_klienci != 0)
  {
    losuj_klienta();
    nowi_klienci--;
  }
}

void Symulator::losuj_kelnera(unsigned int identyfikator)
{

  restauracja.dodaj_kelnera();
}

void Symulator::losuj_klienta()
{


  restauracja.dodaj_klienta();
}


void Symulator::losuj_danie()
{




}

