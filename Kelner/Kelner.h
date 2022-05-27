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
public:
    Kelner();
    Kelner(string imie, unsigned int numer_id);
    string daj_imie();
    unsigned int daj_id();
    bool czy_zajety();
    friend std::ostream& operator<<(std::ostream& os, Kelner& kelner);
};
