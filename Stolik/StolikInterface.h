#pragma once
#include "Stolik.h"

class Stolik
{
public:
    virtual unsigned int daj_numer() = 0;
    virtual unsigned int daj_ilosc_miejsc() = 0;
    virtual void ustaw_status(bool czy_wolny) = 0;
    virtual bool czy_wolny() = 0;

    virtual ~Stolik() = 0;
};
