#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr ;

#include <algorithm>

using std::find; using std::remove;

#include "Menu.hpp"
#include "../BłędyWejścia.h"


// Menu::Menu(vector<unique_ptr<Danie>> inicjalizujace_dania)
// {
//   this -> utworzone_dania = std::move(inicjalizujace_dania);

//   policzone_ceny.clear();
//   policzone_priorytety.clear();
// }

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
