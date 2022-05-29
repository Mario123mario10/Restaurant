#pragma once
#include "Napój.hpp"


class CieplyNapoj: public Napoj
{
  static unsigned int licznik_dan;
  public:
    CieplyNapoj(string nazwa, Kwota koszt_przygotowania);
    void wyswietl() override;
};
