#pragma once
#include "../Danie.hpp"

class Napoj: public Danie
{
  static unsigned int licznik_dan;
  public:
    Napoj
    (
      string nazwa,
      Kwota koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};

