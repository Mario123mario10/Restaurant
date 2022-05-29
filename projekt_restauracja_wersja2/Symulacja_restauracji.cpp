#include "Restauracja.h"
#include "Losowanie.h"
#include "Inne_klasy.h"
#include "Akcja.h"
#include "Akcje_dla_zamowienia.h"

Symulacja_restauracji::Symulacja_restauracji(Restauracja restauracja)
{
    this -> restauracja = restauracja;
}

void Symulacja_restauracji::startuj()
{
    for (int i = 0; i < 20; i++)
    {
        krok_symulacji();
    }
}
void Symulacja_restauracji::krok_symulacji()
{
    int prawdopodobienstwo_nowych_klientow = rand() % 100;
    if (prawdopodobienstwo_nowych_klientow < 30)
    {
        wywolaj_funkcje_inicjacyjna();
    }
    else
    {
        wywolaj_funkcje_kontynuacyjna();
    }


}

void Symulacja_restauracji::wywolaj_funkcje_inicjacyjna()
{
    int losowa_ilosc_osob = rand() % 5;
    vector <Stolik> wektor_stolikow = restauracja.daj_wolne_stoliki();
    Akcja_inicjacyjna akcja(wektor_stolikow[0], losowa_ilosc_osob, restauracja);
    akcja.wykonaj_akcje();

}

void Symulacja_restauracji::wywolaj_funkcje_kontynuacyjna()
{
    unsigned int ilosc_zamowien = restauracja.daj_ilosc_aktualnych_zamowien();
    unsigned int losowa_indeks_zamowienia = rand() % ilosc_zamowien;

    Obsluga_zamowienia wylosowane_zamowienie = restauracja.daj_zamowienie(losowa_indeks_zamowienia);
    Akcje_dla_zamowienia akcje(wylosowane_zamowienie);
    vector <Akcja> dostepne_akcje = akcje.pokaz_dostepne_akcje();
    unsigned int indeks_losowej_akcji = rand() % dostepne_akcje.size();
    auto wylosowana_akcja = dostepne_akcje[indeks_losowej_akcji];   // nie można utworzyć klasy Akcja, bo jest to klasa abstrakcyjna
    wylosowana_akcja.wykonaj_akcje();



}


