#pragma once
#include "Restauracja.h"

class Symulacja_restauracji
{
    Restauracja restauracja;

    Symulacja_restauracji(Restauracja restauracja);

    void startuj();

    void krok_symulacji();

    void wywolaj_funkcje_inicjacyjna();

    void wywolaj_funkcje_kontynuacyjna();
};


