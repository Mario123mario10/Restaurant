#include <string>
using std::string;

#include "../catch.hpp"
#include "../Klient.h"

TEST_CASE("Ustawianie i sprawdzanie atrybutow klienta", "[Klient]")
{
    Klient klient("Jan", true);
    CHECK(Klient.czy_dosiada_sie() = true);
    CHECK(Klient.daj_imie() = "Jan");

}

