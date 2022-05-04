#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr ;

#include <algorithm>

using std::find; using std::remove;

#include "Menu.hpp"
#include "wyjątki.hpp"


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
  policzone_priorytety.clear();
}

void Menu::policz_ceny()
{
  policzone_ceny.clear();
  for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
  {
    string nazwa = (wskaznik -> daj_nazwe());
    string cena =  std::to_string(wskaznik -> policz_cene());
    policzone_ceny.push_back(nazwa + " " + cena);
  }
}

// vector<unique_ptr<Danie>> Menu::daj_dania()
// {
//   return move(utworzone_dania);
// }

vector<string> Menu::daj_ceny()
{ return policzone_ceny         ;}

vector<string> Menu::daj_priorytety()
{ return policzone_priorytety   ;}


void Menu::policz_priorytety()
{
  //
  policzone_priorytety.clear();
  for (const unique_ptr<Danie>& wskaznik: utworzone_dania)
  {
    string nazwa = wskaznik -> daj_nazwe();
    string priorytet =  std::to_string(wskaznik -> policz_priorytet());
    policzone_priorytety.push_back(nazwa + " " + priorytet);
  }
}

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

void Menu::kasuj_danie(std::unique_ptr<Danie> inne_danie)
{
  bool usunieto = false;
  for (int indeks = 0; indeks < utworzone_dania.size(); indeks++)
  {
    if
    (
      (utworzone_dania[indeks] -> daj_nazwe() == inne_danie -> daj_nazwe())
      and
      (utworzone_dania[indeks] -> daj_kategorie() == inne_danie -> daj_kategorie())
    )
    {
      utworzone_dania.erase(utworzone_dania.begin() + indeks);
      usunieto = true;
    }
  }
  if (not usunieto)
  { throw DanieNieIstnieje(move(inne_danie)) ;}
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

void Menu::wyczysc_menu()
{ utworzone_dania.clear() ;}


