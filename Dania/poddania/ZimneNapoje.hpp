#include "Napój.hpp"
#include "../../Kwota/Kwota.h"

class ZimnyNapoj: public Napoj
{
  static unsigned int licznik_dan;
  public:
    ZimnyNapoj
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    friend std::ostream&  operator<<(std::ostream& os, ZimnyNapoj& Danie);

};
