#pragma once


class Stolik
{
    unsigned int numer;
    unsigned int ilosc_miejsc;
    bool wolny;
    unsigned int licznik_stolikow;

public:
    Stolik();
    Stolik(unsigned int ilosc_miejsc, bool wolny=true);
    unsigned int daj_numer();
    unsigned int daj_ilosc_miejsc();
    bool czy_wolny();
    friend std::ostream& operator<<(std::ostream& os, Stolik& stolik);
};
