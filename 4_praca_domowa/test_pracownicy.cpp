// #define CATCH_CONFIG_MAIN
// #include "pomocnik_kucharza.h"
// #include "kucharz.h"
// #include "dostawca.h"
// #include "kierownik.h"
// #include "catch.hpp"
// #include "kelner.h"
// #include "pracownik.h"
// #include "restauracja.h"
// #include "czas.h"
// #include "element_grafiku.h"
// #include "grafik.h"
// using namespace std;

// TEST_CASE("Testy dla kelnera", "[kelner]")
// {
//     Czas c1(10, 15);
//     Czas c2(12, 45);

//     unique_ptr <Pracownik> kelner1 = make_unique <Kelner> ("Karol", "Luczak", c1, c2, 1, 5, 1);
//     CHECK(kelner1 -> get_imie() == "Karol");
//     CHECK(kelner1 -> get_nazwisko() == "Luczak");
//     CHECK(kelner1 -> obliczanie_wynagrodzenia() == 0);
//     CHECK(dynamic_cast<Kelner*> (kelner1.get()) -> get_godzina_poczatkowa() == c1);
//     CHECK(dynamic_cast<Kelner*> (kelner1.get()) -> get_godzina_koncowa() == c2);
//     CHECK(dynamic_cast<Kelner*> (kelner1.get()) -> get_stawka_godzinowa() == 1);
//     CHECK(dynamic_cast<Kelner*> (kelner1.get()) -> get_kara_dzienna() == 5);
//     CHECK(dynamic_cast<Kelner*> (kelner1.get()) -> get_napiwki_za_godzine() == 1);

//     //też może nawet tak być, wtedy nie trzeba tak kombinować (Kelner zamiast Pracownik)

//     // unique_ptr <Kelner> kelner1 = make_unique <Kelner> ("Karol", "Luczak", c1, c2, 1, 5, 1);
//     // CHECK(kelner1 -> get_imie() == "Karol");
//     // CHECK(kelner1 -> get_nazwisko() == "Luczak");
//     // CHECK(kelner1 -> obliczanie_wynagrodzenia() == 0);
//     // CHECK(kelner1 -> get_godzina_poczatkowa() == c1);


// }
// TEST_CASE("Testy dla kucharza", "[kucharz]")
// {
//     Czas c1(10, 15);
//     Czas c2(12, 45);

//     unique_ptr <Pracownik> kucharz1 = make_unique <Kucharz> ("Piotr", "Kowalski", c1 , c2, 2);
//     CHECK(kucharz1 -> get_imie() == "Piotr");
//     CHECK(kucharz1 -> get_nazwisko() == "Kowalski");
//     CHECK(kucharz1 -> obliczanie_wynagrodzenia() == 125);
//     CHECK(dynamic_cast<Kucharz*> (kucharz1.get()) -> get_godzina_poczatkowa() == c1);
//     CHECK(dynamic_cast<Kucharz*> (kucharz1.get()) -> get_godzina_koncowa() == c2);
//     CHECK(dynamic_cast<Kucharz*> (kucharz1.get()) -> get_stawka_godzinowa() == 2);
// }

// TEST_CASE("Testy dla kierownika", "[kierownik]")
// {
//     Czas c1(10, 15);
//     Czas c2(12, 45);

//     unique_ptr <Pracownik> kierownik1 = make_unique <Kierownik> ("Jan", "Mazurek", 5, 10);
//     CHECK(kierownik1 -> get_imie() == "Jan");
//     CHECK(kierownik1 -> get_nazwisko() == "Mazurek");
//     CHECK(kierownik1 -> obliczanie_wynagrodzenia() == 135);
//     CHECK(dynamic_cast<Kierownik*> (kierownik1.get()) -> get_pensja_dzienna() == 5);
//     CHECK(dynamic_cast<Kierownik*> (kierownik1.get()) -> get_premia() == 10);
// }
// TEST_CASE("Testy dla pomocnika kucharza", "[pomocnik kucharza]")
// {
//     Czas c1(10, 15);
//     Czas c2(12, 45);

//     unique_ptr <Pracownik> pomocnik_kucharza1 = make_unique <Pomocnik_kucharza> ("Jan", "Barysz", c1, c2, 4);
//     CHECK(pomocnik_kucharza1 -> get_imie() == "Jan");
//     CHECK(pomocnik_kucharza1 -> get_nazwisko() == "Barysz");
//     CHECK(pomocnik_kucharza1 -> obliczanie_wynagrodzenia() == 100);
//     CHECK(dynamic_cast<Pomocnik_kucharza*> (pomocnik_kucharza1.get()) -> get_godzina_poczatkowa() == c1);
//     CHECK(dynamic_cast<Pomocnik_kucharza*> (pomocnik_kucharza1.get()) -> get_godzina_koncowa() == c2);
//     CHECK(dynamic_cast<Pomocnik_kucharza*> (pomocnik_kucharza1.get()) -> get_pensja_dzienna() == 4);
// }
// TEST_CASE("Testy dla dostawcy", "[dostawca]")
// {

//     Czas c1(10, 15);
//     Czas c2(12, 45);
//     Czas c3(15, 30);
//     Czas c4(18, 45);
//     Element_grafiku element1(c1, c2, PONIEDZIALEK);
//     Element_grafiku element2(c2, c4, WTOREK);
//     Element_grafiku element3(c1, c2, SRODA);
//     Element_grafiku element4(c1, c4, CZWARTEK);
//     Element_grafiku element5(c1, c2, PIATEK);
//     Element_grafiku element6(c2, c3, SOBOTA);
//     Element_grafiku element7(c1, c4, NIEDZIELA);
//     Grafik grafik1;
//     grafik1.dodaj_do_grafiku(element1);
//     grafik1.dodaj_do_grafiku(element2);
//     grafik1.dodaj_do_grafiku(element3);
//     grafik1.dodaj_do_grafiku(element4);
//     grafik1.dodaj_do_grafiku(element5);
//     grafik1.dodaj_do_grafiku(element6);
//     grafik1.dodaj_do_grafiku(element7);

//     unique_ptr <Pracownik> dostawca1 = make_unique <Dostawca> ("Mario", "Czajka", grafik1, 5, 4);
//     CHECK(dostawca1 -> get_imie() == "Mario");
//     CHECK(dostawca1 -> get_nazwisko() == "Czajka");
//     CHECK(dostawca1 -> obliczanie_wynagrodzenia() == 669);
//     CHECK(dynamic_cast<Dostawca*> (dostawca1.get()) -> get_grafik() == grafik1);
//     CHECK(dynamic_cast<Dostawca*> (dostawca1.get()) -> get_grafik().laczna_liczba_godzin() == 33.25);
//     CHECK(dynamic_cast<Dostawca*> (dostawca1.get()) -> get_stawka_za_dostawe_raz_na_godzine() == 5);
//     CHECK(dynamic_cast<Dostawca*> (dostawca1.get()) -> get_pensja_stala_za_miesiac() == 4);
// }
