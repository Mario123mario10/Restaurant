#include <string>
using std::string;

#include <iostream>
using std::cout;        using std::cerr;        using std::endl;

#include <memory>
using std::unique_ptr ;

#include <stdexcept>
using std::invalid_argument;


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

class NieprawidloweRozmiaryStolow: public invalid_argument
{
  public:
    NieprawidloweRozmiaryStolow(string komunikat);
};




// class NiepoprawnaNazwa: public invalid_argument
// {
//   public:
//     NiepoprawnaNazwa(string zla_nazwa);
// };

// class NiepoprawnyKoszt: public invalid_argument
// {
//   public:
//     NiepoprawnyKoszt(unsigned int zly_koszt);
// };

// class NiepoprawnyCzasPrzygotowania: public invalid_argument
// {
//   public:
//     NiepoprawnyCzasPrzygotowania(unsigned int zly_czas);
// };

// class NiepoprawnyPostepPrzygotowania: public invalid_argument
// {
//   public:
//     NiepoprawnyPostepPrzygotowania(unsigned int zly_czas);
// };

// class DanieJuzIstnieje: public invalid_argument
// {
//   public:
//     DanieJuzIstnieje(unique_ptr<Danie> wskaznik_na_danie);
// };

// class DanieNieIstnieje: public invalid_argument
// {
//   public:
//     DanieNieIstnieje(unique_ptr<Danie> wskaznik_na_danie);
// };
