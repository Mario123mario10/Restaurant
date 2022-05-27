#include <vector>
#include <memory>

#include "../ObsługiPlików/ObsługaWyjściowa.h"
#include "../Akcje/ObsługaZamówienia.h"
#include "../Menu/Menu.hpp"
#include "../Klient/Klient.h"
using std::unique_ptr;
// vector <Kelner> wolni_kelnerzy;
//     vector <Stolik> wolne_stoliki;


class Restauracja
{
    vector <ObslugaZamowienia> zamowienia_aktualne;
    vector <ObslugaZamowienia> zamowienia_zamkniete;
    vector <unique_ptr<Kelner>> wolni_kelnerzy;
    vector <unique_ptr<Stolik>> wolne_stoliki;
    vector <unique_ptr<Klient>> nieobslugiwani_klienci;
    Menu menu;
    ObslugaWyjsciowa wyjscie;
    int dochod;

public:
    Restauracja(string nazwa, string nazwa_pliku_wyjscia);
    void uplyw_czasu();

    void pokaz_status_kelnerow();
    void pokaz_status_zamowien();
    void pokaz_status_stolikow();

    void dodaj_klienta(unique_ptr<Klient> wchodzacy_klient);
    void dodaj_kelnera(unique_ptr<Kelner> kelner);
    void dodaj_stolik(unique_ptr<Stolik> stolik);

    void sprawdz_klientow();
    void sprawdz_stoliki();
    void sprawdz_kelnerow();

    void zwolnij_stoliki();
    void zwolnij_kelnerow();

    void stworz_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik);
    void przydziel_klienta();



    void dodaj_zamowienie(ObslugaZamowienia zamowienie);
    void zamknij_zamowienie(ObslugaZamowienia zamowienie);
    ObslugaZamowienia daj_zamowienie(int index);
    vector <Stolik> daj_wolne_stoliki();
    Kelner daj_kelnera(unsigned int index);
    Danie* daj_potrawe(unsigned int numer);  // wszystko co ma rodzaje i ma podklasy ma wskaźniki
    Menu daj_menu();
    unsigned int daj_ilosc_aktualnych_zamowien();

};


// class RestauracjaSzkic
// {
//   // private:
//   //   string nazwa;
//   public:
//     RestauracjaSzkic() {};
//     RestauracjaSzkic(
//       string nazwa,
//       unsigned int rozmiar_maly,
//       unsigned int rozmiar_sredni,
//       unsigned int rozmiar_duzy,
//       unsigned int male,
//       unsigned int sredni,
//       unsigned int duze
//     ) {};
//     void tiktok() {};
//     void dodaj_klienta() {};
// };
