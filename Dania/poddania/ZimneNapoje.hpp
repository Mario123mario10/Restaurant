#include "Napój.hpp"
#include "../../Kwota/Kwota.h"

class ZimnyNapoj: public Napoj
{
  public:
    ZimnyNapoj
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    void wyswietl() override;
};
