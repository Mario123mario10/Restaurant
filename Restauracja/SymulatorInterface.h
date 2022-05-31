#pragma once
#include "Symulator.h"

class Symulator
{
  public:
    virtual void rozpocznij_symulacje() = 0;
    virtual void losuj_kelnera() = 0;
    virtual void losuj_klientow() = 0;
    virtual void losuj_klienta() = 0;
    virtual string losuj_nazwisko() = 0;
    virtual ~Symulator() = 0;

};
