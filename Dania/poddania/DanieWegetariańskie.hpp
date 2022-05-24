#include "DanieGłówne.hpp"



class DanieWegetarianskie: public DanieGlowne
{
  public:
    DanieWegetarianskie
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    void wyswietl() override;
};
