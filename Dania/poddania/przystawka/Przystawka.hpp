#include "Danie.hpp"

class Przystawka: public Danie
{
  public:
    Przystawka
    (
      string nazwa,
      unsigned int koszt_przygotowania
    );

    void wyswietl() override;
};
