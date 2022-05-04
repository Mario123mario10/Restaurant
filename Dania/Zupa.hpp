
#include "DanieGłówne.hpp"


class Zupa: public DanieGlowne
{
  public:
    Zupa
    (
      string nazwa,
      unsigned int koszt_przygotowania
    );
    void wyswietl() override;
};
