#pragma once
#include "Danie.hpp"

class Napoj: public Danie
{
  public:
    Napoj
    (
      string nazwa,
      unsigned int koszt_przygotowania,
      unsigned int czas_przygotowania
    );
};

