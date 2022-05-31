#include <string>
using std::string;

#include "../catch.hpp"
#include "../Stolik.h"

TEST_CASE("Ustawianie i sprawdzanie atrybutow stolika", "[Stolik]")
{
    Stolik stolik(5);
    CHECK(stolik.daj_ilosc_miesc() == 5);


}
