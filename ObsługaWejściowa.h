#pragma once
#include <fstream>
using std::ios; using std::fstream; using std::getline;
#include <memory>
using std::unique_ptr ;
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <string>
using std::string;

#include "Restauracja.h"
#include "Menu.hpp"

class ObslugaWejsciowa
{
  private:
    fstream plik_konfiguracyjny;
    fstream plik_menu;
    string sciezka_konfiguracyjna;
    string nazwa_pliku_wyjscia;
    string sciezka_menu;
    string nazwa_restauracji;
    unsigned int rozmiar_maly;
    unsigned int rozmiar_sredni;
    unsigned int rozmiar_duzy;
    unsigned int male;
    unsigned int srednie;
    unsigned int duze;
    unsigned int czas_trwania_symulacji;
    unsigned int liczba_kelnerow;
    unsigned int liczba_kucharzy;

  public:
    Menu menu;

    ObslugaWejsciowa(string sciezka);

    string daj_nazwe_pliku_wyjscia();
    string daj_nazwe_restauracji();
    unsigned int daj_rozmiar_maly();
    unsigned int daj_rozmiar_sredni();
    unsigned int daj_rozmiar_duzy();
    unsigned int daj_male_stoliki();
    unsigned int daj_srednie_stoliki();
    unsigned int daj_duze_stoliki();
    unsigned int daj_czas_symulacji();
    unsigned int daj_liczbe_kucharzy();
    unsigned int daj_liczbe_kelnerow();

    void pobierz_konfiguracje();
    void pobierz_menu();
    void pobierz_linie_konfiguracji();
    void pobierz_linie_menu();

    void sprawdz_konfiguracje();
    void sprawdz_menu();

    void sprawdz_rozmiary();
    void zdefiniuj_blad_konfiguracji();
    void zdefiniuj_blad_menu();
};


