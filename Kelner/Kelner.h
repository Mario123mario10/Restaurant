#pragma once

#include <string>
#include <vector>
using namespace std;
// #include "../Akcje/ObsługaZamówienia.h"

class Kelner
{
    unsigned int numer_id;
    string imie;
    bool zajety;
    static unsigned int licznik_kelnerow;
public:
    Kelner();
    Kelner(string imie);
    bool czy_zajety();
    string daj_imie();
    unsigned int daj_id();

    void ustaw_imie(string imie);
    void ustaw_id(unsigned int nowe_id);
    void ustaw_zajety(bool czy_zajety);

    friend std::ostream& operator<<(std::ostream& os, Kelner& kelner);
};
