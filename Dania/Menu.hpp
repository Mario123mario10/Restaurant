#pragma once

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr ;

#include "Danie.hpp"


class Menu
{
  private:
    vector<unique_ptr<Danie>> utworzone_dania;
    vector<string> policzone_ceny;
    vector<string> policzone_priorytety;

  public:
    Menu();
    // Menu(vector <std::unique_ptr<Danie>> inicjalizacyjne_dania);
    vector<unique_ptr<Danie>> daj_dania();
    vector<string>            daj_ceny();
    vector<string>            daj_priorytety();

    void dodaj_danie(unique_ptr<Danie> nowe_danie);
    void kasuj_danie(unique_ptr<Danie> inne_danie);
    void policz_ceny();
    void policz_priorytety();
    void wyswietl_menu();
    void wyczysc_menu();
};
