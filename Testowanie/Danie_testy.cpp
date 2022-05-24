// #include <vector>
// using std::vector;
// #include <string>
// using std::string;

// #include "catch.hpp"
// #include "../Danie.hpp"


// using KP = KategoriaPotrawy;


// TEST_CASE("Dawacze i ustawiacze", "[Danie]")
// {
//   Danie danie("Budyń", 20, 3, KP::DESER);
//   CHECK(danie.daj_nazwe() == "Budyń");
//   CHECK(danie.daj_koszt_przygotowania() == 20);
//   CHECK(danie.daj_czas_przygotowania() == 3);
//   CHECK(danie.daj_kategorie() == KP::DESER);
//   CHECK(danie.daj_czas_oczekiwania() == 0);
//   CHECK(danie.daj_postep_przygotowania() == 0);
//   CHECK(danie.czy_przygotowane() == false);

//   SECTION("ustawiacz nazwy")
//   {
//     danie.ustaw_nazwe("Pyszny Budyń");
//     CHECK(danie.daj_nazwe() == "Pyszny Budyń");
//     CHECK_THROWS_WITH(danie.ustaw_nazwe(""), "Zła nazwa: ");
//   }

//   SECTION("ustawiacz kosztu przygotowania")
//   {
//     danie.ustaw_koszt_przygotowania(40);
//     CHECK(danie.daj_koszt_przygotowania() == 40);
//     CHECK_THROWS_WITH(danie.ustaw_koszt_przygotowania(0), "Zły koszt przygotowania: 0");
//   }

//   SECTION("ustawiacz czasu przygotowania")
//   {
//     danie.ustaw_czas_przygotowania(4);
//     CHECK(danie.daj_czas_przygotowania() == 4);
//     CHECK_THROWS_WITH(danie.ustaw_czas_przygotowania(0), "Zły czas przygotowania: 0");
//   }

//   SECTION("ustawiacz czasu oczekiwania")
//   {
//     danie.ustaw_czas_oczekiwania(4);
//     CHECK(danie.daj_czas_oczekiwania() == 4);
//   }

//   SECTION("ustawiacz postępu przygotowania")
//   {
//     danie.ustaw_postep_przygotowania(1);
//     CHECK(danie.daj_postep_przygotowania() == 1);
//     CHECK_THROWS_WITH(danie.ustaw_postep_przygotowania(100), "Zły postęp przygotowania: 100");
//   }

//   SECTION("ustawiacz flagi przygotowania")
//   {
//     danie.ustaw_czy_przygotowane(true);
//     CHECK(danie.czy_przygotowane() == true);
//   }
// }

// TEST_CASE("Funkcje główne", "[SMS_message]")
// {
//   Danie danie("Budyń", 20, 3, KP::DESER);
//   SECTION("policz_cene")
//   {
//     CHECK(danie.policz_cene() == 26);
//   }

//   SECTION("policz priorytet")
//   {
//     CHECK(danie.policz_priorytet() == 2);
//   }

//   SECTION("przygotowuj")
//   {
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 1);
//     CHECK(danie.czy_przygotowane() == false);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 2);
//     CHECK(danie.czy_przygotowane() == false);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 3);
//     CHECK(danie.czy_przygotowane() == true);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 3);
//     CHECK(danie.czy_przygotowane() == true);
//   }
// }

// TEST_CASE("Klasy", "[SMS_message]")
// {
//   Danie danie("Budyń", 20, 3, KP::DESER);
//   SECTION("policz_cene")
//   {
//     CHECK(danie.policz_cene() == 26);
//   }

//   SECTION("policz priorytet")
//   {
//     CHECK(danie.policz_priorytet() == 2);
//   }

//   SECTION("przygotowuj")
//   {
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 1);
//     CHECK(danie.czy_przygotowane() == false);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 2);
//     CHECK(danie.czy_przygotowane() == false);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 3);
//     CHECK(danie.czy_przygotowane() == true);
//     danie.przygotowuj();
//     CHECK(danie.daj_postep_przygotowania() == 3);
//     CHECK(danie.czy_przygotowane() == true);
//   }
// }

