#include <string>
using std::string;

#include "../catch.hpp"
#include "../ObsługaWyjściowa.h"

TEST_CASE("Ustawienie i sprawdzanie atrybutow Obslugi wyjsciowej", "[Obsluga wyjsciowa]")
{
    ObslugaWyjsciowa wyjscie("plik.txt");
    CHECK(wyjscie.daj_nazwe_pliku_wyjscia() == "plik.txt");

    SECTION("Zmiana pliku wyjsciowego", "[Obsluga wyjsciowa]")
    {
        wyjscie.ustaw_nazwe_pliku_wyjscia("plik2.txt");
        CHECK(wyjscie.daj_nazwe_pliku_wyjscia() == "plik2.txt")
    }

}
