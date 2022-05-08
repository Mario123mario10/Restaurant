#include "DanieGłówne.hpp"



class DanieWegetarianskie: public DanieGlowne
{
  public:
    DanieWegetarianskie
    (
      string nazwa,
      unsigned int koszt_przygotowania
    );

    void wyswietl() override;
};
