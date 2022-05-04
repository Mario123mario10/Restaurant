#pragma once
#include "Napój.hpp"


class CieplyNapoj: public Napoj
{
  public:
    CieplyNapoj(string nazwa, unsigned int koszt_przygotowania);

    void wyswietl() override;
};
