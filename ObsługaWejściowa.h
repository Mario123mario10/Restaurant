#include <fstream>
using std::ios; using std::fstream; using std::getline;
#include <memory>
using std::unique_ptr ;
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <string>
using std::string;

#include "Restauracja.h"

class ObslugaWejsciowa
{
  private:
    unique_ptr<Restauracja> restauracja; //
    fstream plik;
    string sciezka;
    string nazwa_restauracji            = "";
    unsigned int rozmiar_maly           = 0;
    unsigned int rozmiar_sredni         = 0;
    unsigned int rozmiar_duzy           = 0;
    unsigned int male                   = 0;
    unsigned int srednie                = 0;
    unsigned int duze                   = 0;
    unsigned int czas_trwania_symulacji = 0;

  public:
    ObslugaWejsciowa(string sciezka);
    // ObslugaWejsciowa(string sciezka, string nazwa_pliku_wyjscia)
    void pobierz_linie();
    void sprawdz_rozmiary();
    void odczytaj_dane();
    void sprawdz_dane();
    void zdefiniuj_blad();
};


