// #include <vector>
// using std::vector;
// #include <string>
// using std::string;
// #include <memory>
// using std::unique_ptr; using std::make_unique;

// #include "catch.hpp"
// #include "../Menu.hpp"
// #include "../Danie.hpp"
// #include "../CiepłeNapoje.hpp"
// #include "../DanieMięsne.hpp"
// #include "../DanieWegetariańskie.hpp"
// #include "../Deser.hpp"
// #include "../Przystawka.hpp"
// #include "../Zupa.hpp"
// #include "../ZimneNapoje.hpp"
// #include "../CiepłeNapoje.hpp"

// using std::move;

// TEST_CASE("Konstruktor", "[Menu]")
// {

//   Menu menu;
//   CHECK(menu.daj_dania().empty() == true);
//   CHECK(menu.daj_priorytety().empty() == true);
//   CHECK(menu.daj_ceny().empty() == true);
// }

// TEST_CASE("Dodawanie różnych dań | operacje na daniach", "[Menu]")
// {
//   Menu menu;
//   unique_ptr<Danie> b = make_unique<Deser>("Budyń", 10);
//   unique_ptr<Danie> s = make_unique<Przystawka>("Sałatka", 5);
//   unique_ptr<Danie> h = make_unique<CieplyNapoj>("Herbata", 3);
//   unique_ptr<Danie> r = make_unique<Zupa>("Rosół", 15);
//   unique_ptr<Danie> k = make_unique<DanieMiesne>("Kotlety", 25);
//   menu.dodaj_danie(move(b));
//   menu.dodaj_danie(move(s));
//   menu.dodaj_danie(move(h));
//   menu.dodaj_danie(move(r));
//   menu.dodaj_danie(move(k));
//   CHECK(menu.daj_priorytety().empty() == true);
//   CHECK(menu.daj_ceny().empty() == true);

//   SECTION("policz ceny")
//   {
//     menu.policz_ceny();
//     CHECK(menu.daj_ceny().size() == 5);
//   }

//   SECTION("policz priorytety")
//   {
//     menu.policz_priorytety();
//     CHECK(menu.daj_priorytety().size() == 5);
//   }

//   SECTION("dodawanie duplikatów")
//   {
//     unique_ptr<Danie> budyn_duplikat = make_unique<Deser>("Budyń", 10);
//     CHECK_THROWS_WITH(menu.dodaj_danie(move(budyn_duplikat)), "Danie o nazwie: Budyń i koszcie przygotowania: 10 już istnieje\n");

//   }

//   SECTION("usuwanie")
//   {
//     unique_ptr<Danie> inny_budyn = make_unique<Deser>("Budyń", 10);
//     unique_ptr<Danie> krupnik = make_unique<Zupa>("Krupnik", 15);
//     CHECK_THROWS_WITH(menu.kasuj_danie(move(krupnik)), "Danie o nazwie: Krupnik i koszcie przygotowania: 15 nie istnieje\n");
//     menu.kasuj_danie(move(inny_budyn));
//     CHECK(menu.daj_dania().size() == 4);
//   }

// }