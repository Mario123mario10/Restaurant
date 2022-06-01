#include <string>
using std::string;

#include "../catch.hpp"
#include "../Stolik.h"

TEST_CASE("Ustawianie i sprawdzanie atrybutow stolika", "[Stolik]")
{
    unsigned int Stolik::licznik_stolikow == 7;

    Stolik stolik(5);
    CHECK(stolik.daj_ilosc_miesc() == 5);
    CHECK(stolik.daj_numer() == 8);

    SECTION("Ustaw status stolika", "[Stolik]")
    {
        stolik.ustaw_status(true);
        CHECK(stolik.czy_wolny() == true);
    }
}
