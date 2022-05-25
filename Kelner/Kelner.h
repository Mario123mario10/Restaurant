#pragma once

#include <string>
#include <vector>
using namespace std;
// #include "../Akcje/ObsługaZamówienia.h"

class Kelner
{

    unsigned int numer_id;
    string imie;
    // vector <ObslugaZamowienia> trwajace_zamowienia;
public:
    Kelner();
    Kelner(string imie);
    string daj_imie();
};
