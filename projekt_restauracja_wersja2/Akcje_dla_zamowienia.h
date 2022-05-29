#pragma once
#include "Obsluga_zamowienia.h"
#include "Akcja.h"
#include <vector>
#include "Inne_klasy.h"


class Akcje_dla_zamowienia  //ta klasa ma ustalac kolejne mozliwe statusy zamowienia
{
   Obsluga_zamowienia aktualne_zamowienie;

public:
    Akcje_dla_zamowienia(Obsluga_zamowienia aktualne_zamowienie);

    vector<Akcja*> akcje_dla_oczekiwania_na_menu();

    vector<Akcja*> akcje_dla_czytania_menu();

    vector<Akcja*> akcje_dla_oczekiwania_na_dania();

    vector<Akcja*> akcje_dla_jedzenia();

    vector<Akcja*> akcje_dla_czekania_na_rachunek();

    vector<Akcja*> akcje_dla_czekania_kelnera_na_zaplate();

    vector<Akcja*> akcje_dla_zaplacenia();

    vector<Akcja*> akcje_dla_wyjscia_z_restauracji();

    vector<Akcja*> akcje_dla_posprzatanego_stolu();  //stol wraca do stolow czystych w klasie restauracja



    vector<Akcja*> pokaz_dostepne_akcje(); // switch dziala jak if


};
