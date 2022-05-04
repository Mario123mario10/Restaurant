#include "Danie.hpp"

class Deser: public Danie
{
  public:
    Deser(string nazwa, unsigned int koszt_przygotowania);
    void wyswietl() override;
};

