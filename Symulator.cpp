#include <string>
using std::string;

#include <memory>
using std::unique_ptr;  using std::make_unique;

#include <random>
#include <chrono>

#include "Symulator.h"
#include "Restauracja.h"
#include "Funkcje_pomocnicze.h"
#include "Menu.hpp"

// unique_ptr<Restauracja> restauracja;
// unsigned int licznik_czasu;
// unsigned int licznik_klientow;
// unsigned int licznik_potraw; // wyszczególnić


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
  restauracja = RestauracjaSzkic(
    nazwa_restauracji,
    rozmiar_maly,
    rozmiar_sredni,
    rozmiar_duzy,
    male,
    srednie,
    duze
  );
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
    restauracja.tiktok();
  }
}

void Symulator::inicjuj_restauracje()
{
  for (int licznik = 1; licznik <= liczba_kucharzy; licznik++)
  { losuj_kucharza(licznik) ;}

  for (int licznik = 0; licznik <= liczba_kelnerow; licznik++)
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

}

void Symulator::losuj_kucharza(unsigned int identyfikator)
{

}

void Symulator::losuj_klienta()
{


  restauracja.dodaj_klienta();
}


void Symulator::losuj_danie()
{


}

// unsigned int Symulator::generuj_liczbe()
// {
//   unsigned int nasiono = std::chrono::system_clock::now().time_since_epoch().count();
//   std::mt19937 generator(nasiono);
//   return generator();
// }

