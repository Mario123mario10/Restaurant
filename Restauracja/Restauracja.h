#include <vector>

#include "../Akcje/ObsługaZamówienia.h"
#include "../Menu/Menu.hpp"

class Restauracja
{

    vector <ObslugaZamowienia> zamowienia_aktualne;
    vector <ObslugaZamowienia> zamowienia_zamkniete;
    vector <Kelner> kelnerzy;
    vector <Stolik> stoliki;
    int dochod;
    Menu menu;

public:
    Restauracja();
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
