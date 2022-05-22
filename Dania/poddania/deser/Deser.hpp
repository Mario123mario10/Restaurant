#include "Danie.hpp"

class Deser: public Danie
{
  public:
    Deser(string nazwa, Kwota koszt_przygotowania);
    void wyswietl() override;
};

