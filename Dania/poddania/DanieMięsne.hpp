#include "DanieGłówne.hpp"



class DanieMiesne: public DanieGlowne
{
  public:
    DanieMiesne
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    void wyswietl() override;
};
