#pragma once
#include <string>
using std::string;

class Potrawa
{
    unsigned int cena_potrawy;
    string nazwa_potrawy;

public:
    Potrawa();
    Potrawa(unsigned int cena_potrawy, string nazwa_potrawy);
    unsigned int podaj_cene();
    string podaj_nazwe();
};

class ZupaSzkic: public Potrawa {};
class DeserSzkic: public Potrawa {};
class NapojSzkic: public Potrawa {};
class DrugieDanieSzkic: public Potrawa {};
class PrzystawkaSzkic: public Potrawa {};
