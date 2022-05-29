#include "DanieGłówne.hpp"



class DanieMiesne: public DanieGlowne
{
  static unsigned int licznik_dan;
  public:
    DanieMiesne
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    void wyswietl() override;
};
