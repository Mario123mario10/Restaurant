#include <iostream>
#include "pracownik.cpp"
#include "restauracja.h"
#include "restauracja.cpp"
using namespace std;
#include <memory>
#include <vector>

int main()
{
    Czas c1(10, 15);
    Czas c2(12, 45);
    Czas c3(15, 30);
    Czas c4(18, 45);
    Element_grafiku element1(c1, c2, PONIEDZIALEK);
    Element_grafiku element2(c2, c4, WTOREK);
    Element_grafiku element3(c1, c2, SRODA);
    Element_grafiku element4(c1, c4, CZWARTEK);
    Element_grafiku element5(c1, c2, PIATEK);
    Element_grafiku element6(c2, c3, SOBOTA);
    Element_grafiku element7(c1, c4, NIEDZIELA);
    Grafik grafik1;
    grafik1.dodaj_do_grafiku(element1);
    grafik1.dodaj_do_grafiku(element2);
    grafik1.dodaj_do_grafiku(element3);
    grafik1.dodaj_do_grafiku(element4);
    grafik1.dodaj_do_grafiku(element5);
    grafik1.dodaj_do_grafiku(element6);
    grafik1.dodaj_do_grafiku(element7);


    unique_ptr <Pracownik> kelner1 = make_unique <Kelner> ("Karol", "Luczak", c1, c2, 1, 5, 1);
    // Pracownik* kelner1 = new Kelner("Karol", "Luczak", c1, c2, 1, 5, 1);
    cout<< kelner1 -> obliczanie_wynagrodzenia();
    kelner1 -> wyswietl_grafik();

    unique_ptr <Pracownik> kucharz1 = make_unique <Kucharz> ("Piotr", "Kowalski",c1 , c2, 2);
    cout<< kucharz1 -> obliczanie_wynagrodzenia();
    kucharz1 -> wyswietl_grafik();

    unique_ptr <Pracownik> kierownik1 = make_unique <Kierownik> ("Jan", "Mazurek", 5, 10);
    cout<< kierownik1 -> obliczanie_wynagrodzenia();
    kierownik1 -> wyswietl_grafik();

    unique_ptr <Pracownik> pomocnik_kucharza1 = make_unique <Pomocnik_kucharza> ("Jan", "Barysz", c1, c2, 4);
    cout<< pomocnik_kucharza1 -> obliczanie_wynagrodzenia();
    pomocnik_kucharza1 -> wyswietl_grafik();

    unique_ptr <Pracownik> dostawca1 = make_unique <Dostawca> ("Mario", "Czajka", grafik1, 5, 4);
    cout<< dostawca1 -> obliczanie_wynagrodzenia();
    dostawca1 -> wyswietl_grafik();
    // Pracownik* dostawca1 = new Dostawca("Mario", "Czajka", grafik1, 5, 4)


    Restauracja restauracja1;
    restauracja1.dodaj_pracownika(move(kelner1));
    restauracja1.dodaj_pracownika(move(kucharz1));
    restauracja1.dodaj_pracownika(move(kierownik1));
    restauracja1.wypisz_pracownikow();



}