#include "DanieGłówne.hpp"
#include "../../Kwota/Kwota.h"

class Zupa: public DanieGlowne
{
  static unsigned int licznik_dan;
  public:
    Zupa
    (
      string nazwa,
      Kwota koszt_przygotowania
    );
    friend std::ostream&  operator<<(std::ostream& os, Zupa& Danie);

};
