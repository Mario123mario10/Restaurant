#pragma once

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr ;

#include "Danie.hpp"


class Menu
{
  private:
    vector<string> policzone_ceny;
    vector<unique_ptr<Danie>> utworzone_dania;
  public:
    Menu();
    vector<string> daj_ceny();
    void przekaz_dania(unique_ptr<Menu> inne_menu);
    void dodaj_danie(unique_ptr<Danie> nowe_danie);
    void policz_ceny();
    void wyswietl_menu();
    bool czy_poprawne();
};
