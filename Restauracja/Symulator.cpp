#include <string>
using std::string;

#include <memory>
using std::unique_ptr;  using std::make_unique;

#include <fstream>
using std::ios; using std::fstream; using std::getline;

#include <random>
#include <chrono>
#include <thread>
#include <chrono>

#include "Symulator.h"
#include "Restauracja.h"
#include "../FunkcjePomocnicze.h"
#include "../Menu/Menu.hpp"
#include "../Stałe.cpp"
#include "../Błędy.h"

Symulator::Symulator
(
  unsigned int czas_trwania_symulacji,
  string nazwa_pliku_wyjscia,
  string nazwa_restauracji,
  string sciezka_do_nazwisk,
  unsigned int rozmiar_maly,
  unsigned int rozmiar_sredni,
  unsigned int rozmiar_duzy,
  unsigned int male,
  unsigned int srednie,
  unsigned int duze,
  unsigned int liczba_kelnerow,
  unsigned int czas_raportowania,
  unique_ptr<Menu> menu
)
{
  restauracja = Restauracja(nazwa_restauracji, nazwa_pliku_wyjscia, move(menu));
  this -> czas_trwania_symulacji = czas_trwania_symulacji;
  this -> sciezka_do_nazwisk = sciezka_do_nazwisk;

  for (int licznik = 1; licznik <= liczba_kelnerow; licznik++)
  { losuj_kelnera() ;}

  for (int licznik = 1; licznik <= male; licznik++)
  {
    unique_ptr<Stolik> stoliczek= make_unique<Stolik>(rozmiar_maly);
    restauracja.dodaj_stolik(move(stoliczek));
  }

  for (int licznik = 1; licznik <= srednie; licznik++)
  {
    unique_ptr<Stolik> stoliczek= make_unique<Stolik>(rozmiar_sredni);
    restauracja.dodaj_stolik(move(stoliczek));
  }

  for (int licznik = 1; licznik <= duze; licznik++)
  {
    unique_ptr<Stolik> stoliczek= make_unique<Stolik>(rozmiar_duzy);
    restauracja.dodaj_stolik(move(stoliczek));
  }

  rozpocznij_symulacje(czas_raportowania);

}
unsigned int Symulator::daj_czas_trwania_symulacji()
{
  return czas_trwania_symulacji;
}


void Symulator::rozpocznij_symulacje(unsigned int czas_raportowania)
{
  for (int licznik = 0; licznik < czas_trwania_symulacji; licznik++)
  {
    if (losuj_liczbe() % SZANSA_NA_BRAK_KLIENTOW == 0)
    { losuj_klientow()  ;}
    restauracja.uplyw_czasu();
    std::this_thread::sleep_for(std::chrono::seconds(czas_raportowania));
  }
}

void Symulator::losuj_klientow()
{
  unsigned int nowi_klienci = losuj_liczbe() % MAX_NOWYCH_KLIENTOW;
  while (nowi_klienci != 0)
  {
    losuj_klienta();
    nowi_klienci--;
  }
}

void Symulator::losuj_kelnera()
{
  unique_ptr<Kelner> nowy_kelner = make_unique<Kelner>(losuj_nazwisko());
  restauracja.dodaj_kelnera(move(nowy_kelner));
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
  plik.open(sciezka_do_nazwisk, ios::in);
  if (plik.is_open())
  {
    unsigned int ilosc_nazwisk = 0;
    string nazwisko;
    while (not plik.eof())
    {
      getline(plik, nazwisko);
      if (not nazwisko.empty())
      { ilosc_nazwisk += 1; }
    }
    plik.clear();
    plik.seekg(0);
    unsigned int numer_linii = losuj_liczbe() % ilosc_nazwisk;
    for (int index = 0; index < numer_linii; index++)
    {
      nazwisko.clear();
      getline(plik, nazwisko);
    }
    plik.close();
    return nazwisko;
  }
  else
  { throw NieZnalezionoPliku(sciezka_do_nazwisk);} // Dodać wyjatek


}



unsigned int Symulator::losuj_liczbe()
{
  unsigned int nasiono = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(nasiono);
  return generator();
}