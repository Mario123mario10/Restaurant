#pragma once
#include "Obsluga_zamowienia.h"
using namespace std;
#include "Restauracja.h"


class Akcja
{
public:
    virtual void wykonaj_akcje() = 0;
};

class Akcja_inicjacyjna : public Akcja //podejscie kolejnych osob do stolika
{
    unsigned int ilosc_osob;
    Stolik stolik;
    Restauracja restauracja;
public:
    Akcja_inicjacyjna(Stolik stolik, unsigned int ilosc_osob, Restauracja restauracja);
    void wykonaj_akcje();
};

class Akcja_kontynuacyjna: public Akcja  //dosiadanie się kolejnych osob do zajetego stolika
{
protected:
    Obsluga_zamowienia obsluga_zamowienia;
public:
    Akcja_kontynuacyjna(Obsluga_zamowienia obsluga_zamowienie);
    virtual void wykonaj_akcje() = 0;

};


        // Obsluga_zamowienia stolik z ludxmi

class Akcja_zanies_menu: public Akcja_kontynuacyjna
{
    Kelner kelner;
public:
    Akcja_zanies_menu(Obsluga_zamowienia obsluga_zamowienia, Kelner kelner);
    void wykonaj_akcje();
};

// kiedy kelner patrzy czy juz mozna pobrac od nich dania i podchodzi kiedy juz stwierdzi ze juz dokonali wyboru
class Zastanawianie_sie_nad_wyborem_dan: public Akcja_kontynuacyjna
{
public:
    Zastanawianie_sie_nad_wyborem_dan(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();
};

class Przyjscie_kolejnych_osob_do_tego_samego_stolika: public Akcja_kontynuacyjna
{
    unsigned int ilosc_kolejnych_osob;
public:
    Przyjscie_kolejnych_osob_do_tego_samego_stolika(Obsluga_zamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob);
    void wykonaj_akcje();
};



class Odebranie_zamowienia_od_stolika: public Akcja_kontynuacyjna // to sie bedzie wykonywalo wiele razy
{
    Potrawa* potrawa; // tu jest wskaznik bo potrawa ma rozne rodzaje
    unsigned int ilosc_sztuk;
public:
    Odebranie_zamowienia_od_stolika(Obsluga_zamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk);

    void wykonaj_akcje();
};

class Czekanie_na_przyniesienie_dan: public Akcja_kontynuacyjna
{
public:
    Czekanie_na_przyniesienie_dan(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();
};

class Podanie_dan_do_stolika: public Akcja_kontynuacyjna
{

public:
    Podanie_dan_do_stolika(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();



};


class Trwa_jedzenie_posilku: public Akcja_kontynuacyjna
{

public:
    Trwa_jedzenie_posilku(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};



class Zakonczenie_wszystkich_posilkow : public Akcja_kontynuacyjna
{
public:
    Zakonczenie_wszystkich_posilkow(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};
class Czekanie_na_rachunek: public Akcja_kontynuacyjna
{
public:
    Czekanie_na_rachunek(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();


};

class Podanie_rachunku_klientom_przez_kelnera: public Akcja_kontynuacyjna
{
public:
    Podanie_rachunku_klientom_przez_kelnera(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class Zaplata_rachunku: public Akcja_kontynuacyjna
{

public:
    Zaplata_rachunku(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class Wyjscie_z_restauracji: public Akcja_kontynuacyjna
{
public:
    Wyjscie_z_restauracji(Obsluga_zamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class Przygotowanie_stolu_dla_nowych_klientow: public Akcja_kontynuacyjna
{
public:
    Przygotowanie_stolu_dla_nowych_klientow(Obsluga_zamowienia Obsluga_zamowienia);

    void wykonaj_akcje();
};


