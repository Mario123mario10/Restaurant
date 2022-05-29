#include <iostream>
#include "Kelner.h"

Kelner::Kelner()
{}

Kelner::Kelner(string imie)
{
    this -> imie = imie;
    this -> numer_id = licznik_kelnerow;
    zajety = false;
    licznik_kelnerow++;
}
string Kelner::daj_imie()
{
    return imie;
}

unsigned int Kelner::daj_id()
{
    return numer_id;
}

bool Kelner::czy_zajety()
{
    return zajety;
}

std::ostream& operator<<(std::ostream& os, Kelner& kelner)
{
    os << "Kelner o nazwisku " << kelner.daj_imie() << " i identyfikatorze " << kelner.daj_id();
    return os;
}

