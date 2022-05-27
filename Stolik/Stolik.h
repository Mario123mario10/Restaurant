#pragma once

enum class WielkoscStolika
{
    maly,
    duzy,
    sredni
};


class Stolik
{
    unsigned int numer;
    unsigned int ilosc_miejsc;
    bool wolny;
    WielkoscStolika wielkosc_stolika;

public:
    Stolik();
    Stolik(unsigned int numer, unsigned int ilosc_miejsc, bool wolny=true);
    unsigned int daj_numer();
    unsigned int daj_ilosc_miejsc();
    bool czy_wolny();
    friend std::ostream& operator<<(std::ostream& os, Stolik& stolik);
};
