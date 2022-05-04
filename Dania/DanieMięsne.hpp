#include "DanieGłówne.hpp"



class DanieMiesne: public DanieGlowne
{
  public:
    DanieMiesne
    (
      string nazwa,
      unsigned int koszt_przygotowania
    );

    void wyswietl() override;
};
