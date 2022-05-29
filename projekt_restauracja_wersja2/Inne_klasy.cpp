
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
//#include "Obsluga_zamowienia.h"
#include "Inne_klasy.h"

Potrawa::Potrawa()
{}

Potrawa::Potrawa(unsigned int cena_potrawy, string nazwa_potrawy)
{
    this -> cena_potrawy = cena_potrawy;
    this -> nazwa_potrawy = nazwa_potrawy;
}

unsigned int Potrawa::podaj_cene()
{
    return cena_potrawy;
}

string Potrawa::podaj_nazwe()
{
    return nazwa_potrawy;
}



Zupa::Zupa()
{}

Zupa::Zupa(unsigned int cena_potrawy, string nazwa_potrawy): Potrawa(cena_potrawy, nazwa_potrawy)
{}


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


Stolik::Stolik()
{}

Stolik::Stolik(unsigned int numer, unsigned int ilosc_miejsc, bool wolny)
{
    this -> numer = numer;
    this -> ilosc_miejsc = ilosc_miejsc;
    this -> wolny = wolny;
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





Rachunek::Rachunek()
{
    czy_rachunek_zaplacony = false;
}
void Rachunek::wyswietl()
{

}
void Rachunek::zaplac()
{
    czy_rachunek_zaplacony = true;
}

