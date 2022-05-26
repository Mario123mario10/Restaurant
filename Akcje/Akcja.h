#pragma once

#include "ObsługaZamówienia.h"
#include "../Kelner/Kelner.h"

class Akcja
{
public:
    virtual ~Akcja();
    virtual void wykonaj_akcje() = 0;
};

class AkcjaInicjacyjna : public Akcja //podejscie kolejnych osob do stolika
{
    unsigned int ilosc_osob;
    Stolik stolik;
public:
    AkcjaInicjacyjna(Stolik stolik, unsigned int ilosc_osob);

    void wykonaj_akcje();
};

class AkcjaKontynuacyjna : public Akcja  //dosiadanie się kolejnych osob do zajetego stolika
{
protected:
    ObslugaZamowienia obsluga_zamowienia;
public:
    AkcjaKontynuacyjna(ObslugaZamowienia obsluga_zamowienie);
};


        // Obsluga_zamowienia stolik z ludxmi

class Akcja_zanies_menu: public AkcjaKontynuacyjna
{
    Kelner kelner;
public:
    Akcja_zanies_menu(ObslugaZamowienia obsluga_zamowienia, Kelner kelner);
    void wykonaj_akcje();
};

// kiedy kelner patrzy czy juz mozna pobrac od nich dania i podchodzi kiedy juz stwierdzi ze juz dokonali wyboru
class RozwazanieWyboruDan: public AkcjaKontynuacyjna
{
public:
    RozwazanieWyboruDan(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();
};

class PrzyjscieKolejnychOsobDoTegoSamegoStolika: public AkcjaKontynuacyjna
{
    unsigned int ilosc_kolejnych_osob;
public:
    PrzyjscieKolejnychOsobDoTegoSamegoStolika(ObslugaZamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob);
    void wykonaj_akcje();
};



class OdebranieZamowieniaOdStolika: public AkcjaKontynuacyjna // to sie bedzie wykonywalo wiele razy
{
    Potrawa* potrawa; // tu jest wskaznik bo potrawa ma rozne rodzaje
    unsigned int ilosc_sztuk;
public:
    OdebranieZamowieniaOdStolika(ObslugaZamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk);
    void wykonaj_akcje();
};

class CzekanieNaPrzyniesienieDan: public AkcjaKontynuacyjna
{
public:
    CzekanieNaPrzyniesienieDan(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();
};

class PodanieDanDoStolika: public AkcjaKontynuacyjna
{

public:
    PodanieDanDoStolika(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();
};


class TrwaJedzeniePosilku: public AkcjaKontynuacyjna
{

public:
    TrwaJedzeniePosilku(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();
};



class ZakonczenieWszystkichPosilkow : public AkcjaKontynuacyjna
{
public:
    ZakonczenieWszystkichPosilkow(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();
};

class CzekanieNaRachunek: public AkcjaKontynuacyjna
{
public:
    CzekanieNaRachunek(ObslugaZamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class PodanieRachunkuKlientomPrzezKelnera: public AkcjaKontynuacyjna
{
public:
    PodanieRachunkuKlientomPrzezKelnera(ObslugaZamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class ZaplataRachunku: public AkcjaKontynuacyjna
{

public:
    ZaplataRachunku(ObslugaZamowienia obsluga_zamowienia);

    void wykonaj_akcje();

};

class WyjscieZRestauracji: public AkcjaKontynuacyjna
{
public:
    WyjscieZRestauracji(ObslugaZamowienia obsluga_zamowienia);
    void wykonaj_akcje();

};

class PrzygotowanieStoluDlaNowychKlientow: public AkcjaKontynuacyjna
{
public:
    PrzygotowanieStoluDlaNowychKlientow(ObslugaZamowienia Obsluga_zamowienia);
    void wykonaj_akcje();
};
