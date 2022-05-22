#ifndef RESTAURACJA_H
#define RESTAURACJA_H


#include <vector>
#include "pracownik.h"
#include <memory>

class Restauracja
{
    vector <unique_ptr<Pracownik>> pracownicy;
    // vector <Pracownik*> pracownicy;


public:
    void dodaj_pracownika(unique_ptr<Pracownik> pracownik);

    // inna wersja// void dodaj_pracownika(Pracownik* pracownik);

    void usun_pracownika(string imie, string nazwisko);

    void wypisz_pracownikow() const;
};

#endif