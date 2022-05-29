#include "Obsluga_zamowienia.h"
//#include "Obsluga_wejsciowa.h"
#include <vector>
#include "Restauracja.h"

Restauracja::Restauracja()
{
    // Konfiguracja konf;
    //ObslugaWejsciowa obsluga("konfiguracja.txt");
    //menu = obsluga.pobierz_menu();


}

void Restauracja::dodaj_zamowienie(Obsluga_zamowienia zamowienie)
{
    zamowienia_aktualne.push_back(zamowienie);
}

void Restauracja::zamknij_zamowienie(Obsluga_zamowienia zamowienie)
{
    vector<Obsluga_zamowienia>::iterator znaleziony_iterator;

    for (vector<Obsluga_zamowienia>::iterator it = zamowienia_aktualne.begin(); it != zamowienia_aktualne.end(); ++it)
    {
        if ((*it).daj_numer_zamowienia() == zamowienie.daj_numer_zamowienia())
        {
            znaleziony_iterator = it;
        }

    }
    zamowienia_aktualne.erase(znaleziony_iterator);
    zamowienia_zamkniete.push_back(zamowienie);
}

Obsluga_zamowienia Restauracja::daj_zamowienie(int index)
{
    return zamowienia_aktualne[index];

}
vector <Stolik> Restauracja::daj_wolne_stoliki()  // chce żeby stoliki to byly klasy zeby moc sprawdzac czy sa zajete czy wolne
{
    vector <Stolik> wolne_stoliki;
    for (Stolik stolik:stoliki)
    {
        if (stolik.czy_wolny() == true)
        {
            wolne_stoliki.push_back(stolik);
        }
    }
    return wolne_stoliki;
}

Kelner Restauracja::daj_kelnera(unsigned int index)
{
    return kelnerzy[index];
}

// Danie* Restauracja::daj_potrawe(unsigned int numer)  // wszystko co ma rodzaje i ma podklasy ma wskaźniki
// {
//     return menu.daj_potrawe(numer);
// }

Menu Restauracja::daj_menu()
{
    return menu;
}
unsigned int Restauracja::daj_ilosc_aktualnych_zamowien()
{
    return zamowienia_aktualne.size();
}





// class Czytanie_plikow
// {
//     Konfiguracja konfiguracja;
// public:
//     Czytanie_plikow(Konfiguracja konfiguracja)
//     {
//         this -> konfiguracja = konfiguracja;
//     }

//     vector <Kelner> czytaj_plik_kelnerow()
//     {

//     }
//     vector <Stolik> czytaj_plik_stoliki()
//     {

//     }
//     Menu czytaj_plik_menu()
//     {

//     }
// };

// class Konfiguracja  // plikow bedzie kazdego rodzaju 1
// {
//     string plik_menu;
//     string plik_kelnerzy;
//     string plik_stoliki;
// public:
//     Konfiguracja()
//     {
//         plik_menu = "menu.txt";
//         plik_kelnerzy = "kelnerzy.txt";
//         plik_stoliki = "stoliki.txt";
//     }

// };

