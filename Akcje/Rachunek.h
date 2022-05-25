#include <vector>
using std::vector;

#include "SzkicePotraw.h"


class PozycjaRachunku
{
    Potrawa danie;
    unsigned int ilosc_sztuk;
};


class Rachunek
{
    vector <PozycjaRachunku> lista_produktow;
    unsigned int cena_laczna;
    bool czy_rachunek_zaplacony;
public:
    Rachunek();
    void wyswietl();
    void zaplac();
};