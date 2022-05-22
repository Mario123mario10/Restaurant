#include <iostream>
#include "restauracja.h"
using namespace std;

// void Restauracja::dodaj_pracownika(Pracownik* pracownik)
// {
//     pracownicy.push_back(pracownik);
// }

void Restauracja::dodaj_pracownika(unique_ptr<Pracownik> pracownik)
{
    pracownicy.push_back(move(pracownik));
}

void Restauracja::wypisz_pracownikow() const
{
    for (auto&& pracownik:pracownicy) //referencja na r-value
    {
        cout<< pracownik->get_imie() << " " << pracownik->get_nazwisko() <<endl;
    }
}
void Restauracja::usun_pracownika(string imie, string nazwisko)
{
    int usuwany_indeks = -1;
    for (int i = 0; i<pracownicy.size(); i++)
    {
        if ((pracownicy[i] -> get_imie() == imie) && (pracownicy[i] -> get_nazwisko() == nazwisko))
        {
            usuwany_indeks = i;
        }
    }
    if (usuwany_indeks != -1)
    {
        pracownicy.erase(pracownicy.begin() + usuwany_indeks);
    }
}