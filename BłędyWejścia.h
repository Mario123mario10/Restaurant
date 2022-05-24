#include <string>
using std::string;

#include <iostream>
using std::cout;        using std::cerr;        using std::endl;

#include <memory>
using std::unique_ptr ;

#include <stdexcept>
using std::invalid_argument;

#include "Dania/Danie.hpp"

class NieZnalezionoPliku: public invalid_argument
{
  public:
    NieZnalezionoPliku(string zla_sciezka);
};

class NiepelnaKonfiguracja: public invalid_argument
{
  public:
    NiepelnaKonfiguracja(string komunikat);
};

class NieprawidloweMenu: public invalid_argument
{
  public:
    NieprawidloweMenu(string komunikat);
};

class NieprawidloweRozmiary: public invalid_argument
{
  public:
    NieprawidloweRozmiary
    (
      unsigned int rozmiar_maly,
      unsigned int rozmiar_sredni,
      unsigned int rozmiar_duzy
    );
};

class NiepoprawnaNazwa: public invalid_argument
{
  public:
    NiepoprawnaNazwa(string zla_nazwa);
};

class DanieJuzIstnieje: public invalid_argument
{
  public:
    DanieJuzIstnieje(unique_ptr<Danie> wskaznik_na_danie);
};

class NiepoprawnyKoszt: public invalid_argument
{
  public:
    NiepoprawnyKoszt(Kwota zly_koszt);
};

class NiepoprawnyCzasPrzygotowania: public invalid_argument
{
  public:
    NiepoprawnyCzasPrzygotowania(unsigned int zly_czas);
};

class NiepoprawnyPostepPrzygotowania: public invalid_argument
{
  public:
    NiepoprawnyPostepPrzygotowania(unsigned int zly_czas);
};




