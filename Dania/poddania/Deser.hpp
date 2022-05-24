#include "../Danie.hpp"
// Dania/poddania/deser/Deser.hpp
// Dania/Danie.hpp
class Deser: public Danie
{
  public:
    Deser(string nazwa, Kwota koszt_przygotowania);
    void wyswietl() override;
};

