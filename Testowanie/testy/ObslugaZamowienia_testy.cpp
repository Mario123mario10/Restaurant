#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr; using std::make_unique;

#include "catch.hpp"
#include "../../ObsługaZamówienia/ObsługaZamówienia.h"
#include "../../Stolik/Stolik.h"
#include "../../Klient/Klient.h"

using std::move;

TEST_CASE("Konstruktor", "[Obsluga zamowienia]")
{
    unique_ptr<Stolik> stolik = make_unique<Stolik>(5);
    unique_ptr<Klient> klient1 = make_unique<Klient>("Jan", true);
    unique_ptr<Klient> klient2 = make_unique<Klient>("Michal", true);
    unique_ptr<Kelner> kelner = make_unique<Kelner>("Karol");
    ObslugaZamowienia zamowienie1(move(stolik), move(klient1));

    CHECK(zamowienie1.daj_numer_zamowienia() == 1);
}
TEST_CASE("przydziel kelnera", "[Obsluga zamowienia]")
{
    unique_ptr<Stolik> stolik = make_unique<Stolik>(5);
    unique_ptr<Klient> klient = make_unique<Klient>("Jan", true);
    unique_ptr<Kelner> kelner = make_unique<Kelner>("Karol");
    ObslugaZamowienia zamowienie1(move(stolik), move(klient));
    zamowienie1.przydziel_kelnera(move(kelner));
    CHECK(zamowienie1.przydzielony_kelner() == true);
}
TEST_CASE("daj numer stolika", "[Obsluga zamowienia]")
{
    unique_ptr<Stolik> stolik = make_unique<Stolik>(5);
    unique_ptr<Klient> klient = make_unique<Klient>("Jan", true);

    ObslugaZamowienia zamowienie1(move(stolik), move(klient));
    CHECK(zamowienie1.daj_numer_stolika() == 1);

}