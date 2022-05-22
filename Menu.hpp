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
  public:
    Menu();
    vector<string> daj_ceny();
    void dodaj_danie(unique_ptr<Danie> nowe_danie);
    void policz_ceny();
    void wyswietl_menu();
};
