#pragma once
#include "Danie.hpp"


class DanieGlowne: public Danie
{
  public:
    DanieGlowne
    (
      string nazwa,
      unsigned int koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};
