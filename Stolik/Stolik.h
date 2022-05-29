#pragma once
#include <iostream>

class Stolik
{
    unsigned int numer;
    unsigned int ilosc_miejsc;
    bool wolny;
    static unsigned int licznik_stolikow;

public:
    Stolik();
    Stolik(unsigned int ilosc_miejsc);
    unsigned int daj_numer();
    unsigned int daj_ilosc_miejsc();
    void ustaw_status(bool czy_wolny);
    bool czy_wolny();
    friend std::ostream& operator<<(std::ostream& os, Stolik& stolik);
};
