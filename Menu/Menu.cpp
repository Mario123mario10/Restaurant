#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr ;
using std::make_unique;

#include <algorithm>

using std::move;
#include "../Restauracja/Symulator.h"
#include "../Błędy.h"
#include "../Dania/poddania/DanieMięsne.hpp"
#include "../Dania/poddania/DanieWegetariańskie.hpp"
#include "../Dania/poddania/Zupa.hpp"
#include "../Dania/poddania/CiepłeNapoje.hpp"
#include "../Dania/poddania/ZimneNapoje.hpp"
#include "../Dania/poddania/Deser.hpp"
#include "../Dania/poddania/Przystawka.hpp"

#include "Menu.hpp"
using KP = KategoriaPotrawy;

Menu::Menu()
{
  utworzone_dania.clear();
  policzone_ceny.clear();
}

void Menu::policz_ceny()
{
  policzone_ceny.clear();
  for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
  {
    string nazwa = (wskaznik -> daj_nazwe());
    string cena =  (string) (wskaznik -> policz_cene());
    policzone_ceny.push_back(nazwa + " " + cena);
  }
}

vector<string> Menu::daj_ceny()
{ return policzone_ceny         ;}

void Menu::dodaj_danie(unique_ptr<Danie> nowe_danie)
{
  for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
  {
    if
    (
      (wskaznik -> daj_nazwe() == nowe_danie -> daj_nazwe())
      and
      (wskaznik -> daj_kategorie() == nowe_danie -> daj_kategorie())
    )
    { throw DanieJuzIstnieje(move(nowe_danie)) ;}
  }
  utworzone_dania.push_back(move(nowe_danie));
}

void Menu::wyswietl_menu()
{
  if (utworzone_dania.empty())
  { cout << "Menu jest puste" << endl ;}
  else
  {
    cout << "Zawartość menu: " << endl;
    for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
    { wskaznik -> wyswietl() ;}
  }
}

bool Menu::czy_poprawne()
{
  bool jest_przystawka  = false;
  bool jest_glowne      = false;
  bool jest_deser       = false;
  bool jest_napoj       = false;

  for (const unique_ptr<Danie>& danie: utworzone_dania)
  {
    if (danie -> daj_kategorie() == KP::DESER)
    { jest_deser = true   ;}
    else if (danie -> daj_kategorie() == KP::DANIE_GLOWNE)
    { jest_glowne = true  ;}
    else if (danie -> daj_kategorie() == KP::NAPOJ)
    { jest_napoj = true  ;}
    else if (danie -> daj_kategorie() == KP::PRZYSTAWKA)
    { jest_przystawka = true  ;}
  }
  return jest_przystawka || jest_glowne || jest_deser || jest_napoj;
}

void Menu::przekaz_dania(unique_ptr<Menu> inne_menu)
{
  for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
  {
    unique_ptr<Danie> inny_wskaznik = make_unique<Danie>(*wskaznik);
    inne_menu -> dodaj_danie(move(inny_wskaznik));
  }
}

unique_ptr<Danie> Menu::wybierz_przystawke()
{
  unique_ptr<Danie> danie;
  while (danie == nullptr)
  {
    unsigned int index = Symulator::losuj_liczbe() % utworzone_dania.size();
    if (utworzone_dania[index] -> daj_kategorie() == KP::PRZYSTAWKA)
    {
      string nazwa = utworzone_dania[index] -> daj_nazwe();
      Kwota koszt = utworzone_dania[index] -> daj_koszt_przygotowania();
      unsigned int czas_przygotowania = utworzone_dania[index] -> daj_czas_przygotowania();
      danie = make_unique<Przystawka>(nazwa, koszt);
    }
  }
  return danie;
}

unique_ptr<Danie> Menu::wybierz_danie_glowne()
{
  unique_ptr<Danie> danie;
  while (danie == nullptr)
  {
    unsigned int index = Symulator::losuj_liczbe() % utworzone_dania.size();
    if (utworzone_dania[index] -> daj_kategorie() == KP::DANIE_GLOWNE)
    {
      string nazwa = utworzone_dania[index] -> daj_nazwe();
      Kwota koszt = utworzone_dania[index] -> daj_koszt_przygotowania();
      unsigned int czas_przygotowania = utworzone_dania[index] -> daj_czas_przygotowania();

      switch (czas_przygotowania)
      {
      case 3:
        danie = make_unique<DanieWegetarianskie>(nazwa, koszt);
        break;
      case 4:
        danie = make_unique<Zupa>(nazwa, koszt);
        break;
      case 8:
        danie = make_unique<DanieMiesne>(nazwa, koszt);
        break;
      default:
        break;
      }
    }
  }
  return danie;
}

unique_ptr<Danie> Menu::wybierz_deser()
{
  unique_ptr<Danie> danie;
  while (danie == nullptr)
  {
    unsigned int index = Symulator::losuj_liczbe() % utworzone_dania.size();
    if (utworzone_dania[index] -> daj_kategorie() == KP::DESER)
    {
      string nazwa = utworzone_dania[index] -> daj_nazwe();
      Kwota koszt = utworzone_dania[index] -> daj_koszt_przygotowania();
      danie = make_unique<Deser>(nazwa, koszt);
    }
  }
  return danie;
}

unique_ptr<Danie> Menu::wybierz_napoj()
{
  unique_ptr<Danie> danie;
  while (danie == nullptr)
  {
    unsigned int index = Symulator::losuj_liczbe() % utworzone_dania.size();
    if (utworzone_dania[index] -> daj_kategorie() == KP::NAPOJ)
    {
      string nazwa = utworzone_dania[index] -> daj_nazwe();
      Kwota koszt = utworzone_dania[index] -> daj_koszt_przygotowania();
      unsigned int czas_przygotowania = utworzone_dania[index] -> daj_czas_przygotowania();

      switch (czas_przygotowania)
      {
      case 1:
        danie = make_unique<ZimnyNapoj>(nazwa, koszt);
        break;
      case 2:
        danie = make_unique<CieplyNapoj>(nazwa, koszt);
        break;
      default:
        break;
      }
    }
  }
  return danie;
}
