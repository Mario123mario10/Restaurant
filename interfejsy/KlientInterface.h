#pragma once
#include "Klient.h"

class Klient
{
public:
    virtual bool czy_dosiada_sie() = 0;
    virtual string daj_imie() = 0;
    virtual unsigned int daj_identyfikator() = 0;
    virtual ~Klient() = 0;
};
