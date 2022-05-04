#pragma once

#include <memory>
using std::unique_ptr ;

#include "Menu.hpp"

class Interfejs
{
  private:
    unique_ptr<Menu> menu;
    bool czy_dziala;
  public:
    Interfejs();
    void pobierz_komende();
    void wyswietl_menu();
    void zakoncz();
    void pomoc();
    unique_ptr<Danie> utworz_danie(string typ, string nazwa, unsigned int koszt);

};
