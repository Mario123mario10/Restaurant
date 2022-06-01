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

using std::move;

#include "../Restauracja.h"
#

TEST_CASE("Ustawienie sprawdzanie atrybutow Restauracji", "[Restauracja]")
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

    Restauracja restauracja("restauracja1", "plik.txt", menu);

    SECTION("Pokazanie bezczynnych kelnerów", "[Restauracja]")
    {
        Kelner kelner1;
        kelner.ustaw_imie("Jan");
        kelner.ustaw_id(1);
        kelner.ustaw_zajety(false);

        Kelner kelner2;
        kelner.ustaw_imie("Marek");
        kelner.ustaw_id(2);
        kelner.ustaw_zajety(false);

        restauracja.dodaj_kelnera(kelner1);
        restauracja.dodaj_kelnera(kelner2);

        CHECK(restauracja.pokaz_bazczynnych_kelnerow() == "Kelner o nazwisku Jan i inentyfikatorze 1 nie obsługuje zamówienia\n
Kelner o nazwisku Marek i inentyfikatorze 2 nie obsługuje zamówienia");
    }

}