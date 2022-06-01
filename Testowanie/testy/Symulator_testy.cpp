#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr; using std::make_unique;

#include "catch.hpp"
#include "../Menu.hpp"
#include "../Danie.hpp"
#include "../CiepłeNapoje.hpp"
#include "../DanieMięsne.hpp"
#include "../DanieWegetariańskie.hpp"
#include "../Deser.hpp"
#include "../Przystawka.hpp"
#include "../Zupa.hpp"
#include "../ZimneNapoje.hpp"
#include "../CiepłeNapoje.hpp"

#include "../Symulator.h"

using std::move;

TEST_CASE("Konstruktor Symulatora", "[Symulator]")
{
    Menu menu;
    unique_ptr<Danie> b = make_unique<Deser>("Budyń", 10);
    unique_ptr<Danie> s = make_unique<Przystawka>("Sałatka", 5);
    unique_ptr<Danie> h = make_unique<CieplyNapoj>("Herbata", 3);
    unique_ptr<Danie> r = make_unique<Zupa>("Rosół", 15);
    unique_ptr<Danie> k = make_unique<DanieMiesne>("Kotlety", 25);
    menu.dodaj_danie(move(b));
    menu.dodaj_danie(move(s));
    menu.dodaj_danie(move(h));
    menu.dodaj_danie(move(r));
    menu.dodaj_danie(move(k));
    Symulator symulator(1000, "plik.txt", "restauracja1", 2, 4, 8, 10, 8, 2, 10, menu);
    CHECK(symulator.daj_czas_trwania_symulacji == 1000);
}
