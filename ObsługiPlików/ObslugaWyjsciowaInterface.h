#pragma once
#include "ObsługaWyjściowa.h"

class ObslugaWyjsciowa
{
  public:
    virtual string daj_nazwe_pliku_wyjscia() = 0;
    virtual void ustaw_nazwe_pliku_wyjscia(string nowa_nazwa) = 0;

    virtual ~ObslugaWyjsciowa() = 0;
};






