

#include "Stolik.h"



Stolik::Stolik()
{}

Stolik::Stolik(unsigned int ilosc_miejsc, bool wolny=true)
{

    this -> numer = licznik_stolikow + 1;
    this -> ilosc_miejsc = ilosc_miejsc;
    this -> wolny = wolny;
    licznik_stolikow++;
}
unsigned int Stolik::daj_numer()
{
    return numer;
}
unsigned int Stolik::daj_ilosc_miejsc()
{
    return ilosc_miejsc;
}
bool Stolik::czy_wolny()
{
    return wolny;
}