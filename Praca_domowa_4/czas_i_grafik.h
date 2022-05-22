#ifndef CZAS_I_GRAFIK_H
#define CZAS_I_GRAFIK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Czas
{
    int godzina;
    int minuty;

public:

    Czas()
    {
        godzina = 0;
        minuty = 0;
    }
    Czas(const int godzina, const int minuty)
    {
        this -> godzina = godzina;
        this -> minuty = minuty;
    }
    bool operator==(const Czas& other) const
    {
        if (godzina == other.godzina && minuty == other.minuty)
        {
            return true;
        }
        return false;
    }
    int get_godzina() const
    {
        return godzina;
    }
    int get_minuty() const
    {
        return minuty;
    }
    void wypisz() const
    {
        cout << godzina << ":" << minuty;
    }

};
enum Dzien_tygodnia
{
    PONIEDZIALEK,
    WTOREK,
    SRODA,
    CZWARTEK,
    PIATEK,
    SOBOTA,
    NIEDZIELA
};

//w elementach grafiku dolozyc
//miesiace enum
//dzien i rok to liczby
class Element_grafiku
{
    Czas godzina_poczatkowa;
    Czas godzina_koncowa;
    Dzien_tygodnia dzien;
public:
    Element_grafiku(Czas godzina_poczatkowa, Czas godzina_koncowa, Dzien_tygodnia dzien)
    {
        this -> godzina_koncowa = godzina_koncowa;
        this -> godzina_poczatkowa = godzina_poczatkowa;
        this -> dzien = dzien;
    }
    bool operator==(const Element_grafiku& other) const
    {
        if (other.godzina_poczatkowa == godzina_poczatkowa)
        {
            return true;
        }
        return false;
    }
    double get_laczny_czas() const
    {
        return godzina_koncowa.get_godzina() - godzina_poczatkowa.get_godzina() + (godzina_koncowa.get_minuty() - godzina_poczatkowa.get_minuty())/60.0;
    }
    void drukuj() const
    {
        godzina_poczatkowa.wypisz();
        cout<< " - ";
        godzina_koncowa.wypisz();
        cout<< " ";
        cout << dzien;
        cout<< ",";
    }
};

class Grafik
{
    vector <Element_grafiku> grafik;
public:
    Grafik()
    {}
    bool operator==(const Grafik& other) const
    {
        if (other.grafik == grafik)
        {
            return true;
        }
        return false;
    }
    void dodaj_do_grafiku(Element_grafiku dzien)
    {
        grafik.push_back(dzien);
    }
    void wyswietl() const
    {
        cout << "grafik:: ";
        for (int i = 0; i< grafik.size(); i++)
        {
            grafik[i].drukuj();
        }
        cout<<"\n";
    }
    double laczna_liczba_godzin() const
    {
        double suma = 0;
        for (int i = 0; i < grafik.size(); i++)
        {
            suma += grafik[i].get_laczny_czas();
        }
        return suma;
    }
};



#endif