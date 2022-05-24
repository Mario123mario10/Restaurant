#pragma once
#include "../Danie.hpp"

class Napoj: public Danie
{
  public:
    Napoj
    (
      string nazwa,
      Kwota koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};

