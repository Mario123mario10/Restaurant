

#include "Stolik.h"

using namespace std;

Stolik::Stolik()
{}

Stolik::Stolik(unsigned int ilosc_miejsc)
{

    this -> numer = licznik_stolikow + 1;
    this -> ilosc_miejsc = ilosc_miejsc;
    this -> wolny = true;
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

void Stolik::ustaw_status(bool czy_wolny)
{
    wolny = czy_wolny;
}

std::ostream& operator<<(std::ostream& os, Stolik& stolik)
{
    os << "Stolik o numerze " << stolik.daj_numer();
    return os;
}
