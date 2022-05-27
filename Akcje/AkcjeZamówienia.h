#include <vector>
#include "ObsługaZamówienia.h"
#include "Akcja.h"
#include "InneKlasy.h"


class AkcjeDlaZamowienia  //ta klasa ma ustalac kolejne mozliwe statusy zamowienia
{
   ObslugaZamowienia aktualne_zamowienie;

public:
    AkcjeDlaZamowienia(ObslugaZamowienia aktualne_zamowienie);

    vector<Akcja> akcje_dla_oczekiwania_na_menu();
    vector<Akcja> akcje_dla_czytania_menu();
    vector<Akcja> akcje_dla_oczekiwania_na_dania();
    vector<Akcja> akcje_dla_jedzenia();
    vector<Akcja> akcje_dla_czekania_na_rachunek();
    vector<Akcja> akcje_dla_czekania_kelnera_na_zaplate();
    vector<Akcja> akcje_dla_zaplacenia();
    vector<Akcja> akcje_dla_wyjscia_z_restauracji();
    vector<Akcja> akcje_dla_posprzatanego_stolu();
    vector<Akcja> pokaz_dostepne_akcje();
};
