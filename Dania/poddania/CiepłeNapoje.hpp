#pragma once
#include "Napój.hpp"


class CieplyNapoj: public Napoj
{
  public:
    CieplyNapoj(string nazwa, Kwota koszt_przygotowania);
    void wyswietl() override;
};
