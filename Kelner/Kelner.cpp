#include "Kelner.h"



Kelner::Kelner()
{}

Kelner::Kelner(string imie, unsigned int numer_id)
{
    this -> imie = imie;
    this -> numer_id = numer_id;
    zajety = false;
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
