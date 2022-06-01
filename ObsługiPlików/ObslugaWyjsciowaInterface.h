#pragma once
#include "ObsługaWyjściowa.h"

class InterfejsObslugaWyjsciowa
{
  public:
    virtual string daj_nazwe_pliku_wyjscia() = 0;
    virtual void ustaw_nazwe_pliku_wyjscia(string nowa_nazwa) = 0;

    virtual ~InterfejsObslugaWyjsciowa() = 0;
};






