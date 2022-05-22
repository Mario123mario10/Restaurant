#include "Danie.hpp"
#include "../Kwota.h"

class Przystawka: public Danie
{
  public:
    Przystawka
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    void wyswietl() override;
};
