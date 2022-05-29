#pragma once
#include "../Danie.hpp"


class DanieGlowne: public Danie
{
  static unsigned int licznik_dan;
  public:
    DanieGlowne
    (
      string nazwa,
      Kwota koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};
