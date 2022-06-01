#pragma once
#include "Kelner.h"

class InterfejsKelner
{
public:
    virtual bool czy_zajety() = 0;
    virtual string daj_imie() = 0;
    virtual unsigned int daj_id() = 0;

    virtual void ustaw_imie(string imie) = 0;
    virtual void ustaw_id(unsigned int nowe_id) = 0;
    virtual void ustaw_zajety(bool czy_zajety) = 0;
    virtual ~InterfejsKelner() = 0;
};
