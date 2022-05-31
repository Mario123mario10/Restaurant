#include <string>
using std::string;

#include "../catch.hpp"
#include "../Kwota.h"

TEST_CASE("Ustawianie i sprawdzanie atrybutow kwoty", "[Kwota]")
{
    Kwota kwota(10, 30);
    CHECK(kwota.daj_zlote() = 10);
    CHECK(kwota.daj_grosze() = 30);
}
TEST_CASE("Dzialanie na kwocie", "[Kwota]")
{
    Kwota kwota1(10, 30);
    Kwota kwota2(20, 10);


    SECTION("operator +", "[Kwota]")
    {
        Kwota kwota3 = kwota1 + kwota2;
        CHECK(kwota3.daj_zlote() = 30);
        CHECK(kwota3.daj_grosze() = 40);
    }
    SECTION("operator == !=", "[Kwota]")
    {
        Kwota kwota3(10, 30);
        CHECK((kwota3 == kwota1) == true);
        CHECK((kwota3 != kwota1) == false);
    }
     SECTION("operator > < >= <=", "[Kwota]")
    {
        Kwota kwota3(10, 40);
        CHECK(kwota3 > kwota1 == true);
        CHECK(kwota3 < kwota1 == false);
        CHECK(kwota3 >= kwota1 == true);
        CHECK(kwota3 <= kwota1 == false);
    }
}
