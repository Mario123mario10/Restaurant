#pragma once
#include "../Danie.hpp"
#include "../../Kwota/Kwota.h"

class Przystawka: public Danie
{
  static unsigned int licznik_dan;
  public:
    Przystawka
    (
      string nazwa,
      Kwota koszt_przygotowania
    );
    void wyswietl() override;
    friend std::ostream&  operator<<(std::ostream& os, Przystawka& Danie);

};
