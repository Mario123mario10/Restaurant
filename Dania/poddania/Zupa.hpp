#include "DanieGłówne.hpp"
#include "../../Kwota/Kwota.h"

class Zupa: public DanieGlowne
{
  public:
    Zupa
    (
      string nazwa,
      Kwota koszt_przygotowania
    );
    void wyswietl() override;
};
