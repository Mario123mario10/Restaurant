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

TEST_CASE("Konstruktor", "[Obsluga zamowienia]")
{
    unsigned int zamowienie1::licznik_zamowien = 10;

    Stolik stolik(5);
    Klient klient1("Jan", true);
    Klient klient2("Michal", true);
    Kelner kelner("Karol");
    ObslugaZamowienia zamowienie1(stolik, klient1);

    CHECK(zamowienie.klienci == {klient1});
    CHECK(zamowienie.daj_numer_zamowienia() == 11);
}
TEST_CASE("przydziel kelnera", "[Obsluga zamowienia]")
{
    Stolik stolik(5);
    Klient klient("Jan", true);
    Kelner kelner("Karol");
    ObslugaZamowienia zamowienie1(stolik, klient);
    zamowienie1.przydziel_kelnera(kelner);

    CHECK(zamowienie.przydzielony_kelner() == true);

}
TEST_CASE("daj numer stolika", "[Obsluga zamowienia]")
{
    unsigned int Stolik::licznik_stolikow == 7;

    Stolik stolik(5);
    Klient klient("Jan", true);

    ObslugaZamowienia zamowienie1(stolik, klient);
    CHECK(zamowienie1.daj_numer_stolika() == 8);

}