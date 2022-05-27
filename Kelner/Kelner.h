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
    Kelner(string imie);
    string daj_imie();
    bool czy_zajety();
    friend std::ostream& operator<<(std::ostream& os, Kelner& kelner);
};
