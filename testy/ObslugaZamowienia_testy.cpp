#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr; using std::make_unique;

#include "catch.hpp"
#include "../ObslugaZamowienia.hpp"
#include "../Stolik.h"
#include "../Klient.h"

using std::move;

TEST_CASE("Konstruktor", "[Menu]")
{

    Stolik stolik(5);
    Klient klient1("Jan", true);
    Klient klient2("Michal", true);
    ObslugaZamowienia zamowienie1(stolik, klient1);
    CHECK(zamowienie.klienci == {klient1});
}
