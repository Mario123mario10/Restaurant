#pragma once
#include "../Danie.hpp"


class DanieGlowne: public Danie
{
  public:
    DanieGlowne
    (
      string nazwa,
      Kwota koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};
