#pragma once
#include "Kwota.h"

class Kwota
{
public:
    virtual int daj_zlote () const = 0;
    virtual int daj_grosze() const = 0;
    virtual void ustaw_zlote(int nowe_zlote) = 0;
    virtual void ustaw_grosze(int nowe_grosze) = 0;
    virtual int jako_grosze() const = 0;
    virtual ~Kwota() = 0;
};
