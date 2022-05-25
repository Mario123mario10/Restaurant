#include "Kelner.h"



Kelner::Kelner()
{}

Kelner::Kelner(string imie)
{
    this -> imie = imie;
}
string Kelner::daj_imie()
{
    return imie;
}