#include <string>
#include "pracownik.h"

string Pracownik::get_imie() const
{
    return imie;
}
string Pracownik::get_nazwisko() const
{
    return nazwisko;
}
Pracownik::Pracownik(string imie2, string nazwisko2)
{
    imie = imie2;
    nazwisko = nazwisko2;
}
Pracownik::Pracownik(Pracownik&& other)
{
    imie = other.get_imie();
    nazwisko = other.get_nazwisko();

}

