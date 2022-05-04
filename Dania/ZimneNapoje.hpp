#include "Napój.hpp"

class ZimnyNapoj: public Napoj
{
  public:
    ZimnyNapoj
    (
      string nazwa,
      unsigned int koszt_przygotowania
    );

    void wyswietl() override;
};
