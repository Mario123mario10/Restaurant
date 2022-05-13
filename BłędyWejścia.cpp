#include <stdexcept>
using std::invalid_argument;

#include <string>
using std::string;

#include <iostream>
using std::cout;        using std::cerr;        using std::endl;

#include "BłędyWejścia.h"
// #include "Danie.hpp"

using std::to_string;


NieZnalezionoPliku::NieZnalezionoPliku(string zla_sciezka):
invalid_argument("Nie znaleziono pliku o podanej scieżce: " + zla_sciezka){}

NiepelnaKonfiguracja::NiepelnaKonfiguracja(string komunikat):
invalid_argument(komunikat) {}

NieprawidloweMenu::NieprawidloweMenu(string komunikat):
invalid_argument(komunikat) {}






// NiepoprawnaNazwa::NiepoprawnaNazwa(string zla_nazwa):
// invalid_argument("Zła nazwa: " + zla_nazwa){}

// NiepoprawnyKoszt::NiepoprawnyKoszt(unsigned int zly_koszt):
// invalid_argument("Zły koszt przygotowania: " + to_string(zly_koszt)) {}

// NiepoprawnyCzasPrzygotowania::NiepoprawnyCzasPrzygotowania(unsigned int zly_czas):
// invalid_argument("Zły czas przygotowania: " + to_string(zly_czas)) {}

// NiepoprawnyPostepPrzygotowania::NiepoprawnyPostepPrzygotowania(unsigned int zly_postep):
// invalid_argument("Zły postęp przygotowania: " + to_string(zly_postep)) {}


// DanieJuzIstnieje::DanieJuzIstnieje(unique_ptr<Danie> wskaznik_na_danie):
// invalid_argument(
//     "Danie o nazwie: "
//     + wskaznik_na_danie -> daj_nazwe()
//     + " i koszcie przygotowania: "
//     + to_string(wskaznik_na_danie -> daj_koszt_przygotowania())
//     + " już istnieje\n"
//     ) {}

// DanieNieIstnieje::DanieNieIstnieje(unique_ptr<Danie> wskaznik_na_danie):
// invalid_argument(
//     "Danie o nazwie: "
//     + wskaznik_na_danie -> daj_nazwe()
//     + " i koszcie przygotowania: "
//     + to_string(wskaznik_na_danie -> daj_koszt_przygotowania())
//     + " nie istnieje\n"
//     ) {}






