#pragma once
#include "Menu.hpp"

class InterfejsMenu
{
  public:
    virtual unique_ptr<Danie> wybierz_przystawke() = 0;
    virtual unique_ptr<Danie> wybierz_danie_glowne() = 0;
    virtual unique_ptr<Danie> wybierz_deser() = 0;
    virtual unique_ptr<Danie> wybierz_napoj() = 0;
    virtual vector<string> daj_ceny() = 0;
    virtual void przekaz_dania(unique_ptr<Menu> inne_menu) = 0;
    virtual void dodaj_danie(unique_ptr<Danie> nowe_danie) = 0;
    virtual void policz_ceny() = 0;
    virtual void wyswietl_menu() = 0;
    virtual bool czy_poprawne() = 0;
    virtual ~InterfejsMenu() = 0;
};
