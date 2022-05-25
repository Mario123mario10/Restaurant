#include "ObsługaZamówienia.h"
#include "../Kelner/Kelner.h"

class Akcja
{
public:
    virtual void wykonaj_akcje() = 0;
};

class AkcjaInicjacyjna : public Akcja //podejscie kolejnych osob do stolika
{
    unsigned int ilosc_osob;
    Stolik stolik;
public:
    AkcjaInicjacyjna(Stolik stolik, unsigned int ilosc_osob)
    {
        this -> ilosc_osob = ilosc_osob;
        this -> stolik = stolik;
    }

    void wykonaj_akcje()
    {
        ObslugaZamowienia zamowienie(stolik, ilosc_osob);
    }


};

class AkcjaKontynuacyjna : public Akcja  //dosiadanie się kolejnych osob do zajetego stolika
{
protected:
    ObslugaZamowienia obsluga_zamowienia;
public:
    AkcjaKontynuacyjna(ObslugaZamowienia obsluga_zamowienie)
    {
        this -> obsluga_zamowienia = obsluga_zamowienia;
    }
};


        // Obsluga_zamowienia stolik z ludxmi

class Akcja_zanies_menu: public AkcjaKontynuacyjna
{
    Kelner kelner;
public:
    Akcja_zanies_menu(ObslugaZamowienia obsluga_zamowienia, Kelner kelner): AkcjaKontynuacyjna(obsluga_zamowienia)
    {
        this -> kelner = kelner;
    }
    void wykonaj_akcje()
    {
        obsluga_zamowienia.przypisz_kelnera_i_zanies_menu(kelner);
    }
};

// kiedy kelner patrzy czy juz mozna pobrac od nich dania i podchodzi kiedy juz stwierdzi ze juz dokonali wyboru
class RozwazanieWyboruDan: public AkcjaKontynuacyjna
{
public:
    RozwazanieWyboruDan(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Zastanawianie sie klientow nad wyborem posilkow przy stole "<< obsluga_zamowienia.daj_stolik().daj_numer();
    }
};

class PrzyjscieKolejnychOsobDoTegoSamegoStolika: public AkcjaKontynuacyjna
{
    unsigned int ilosc_kolejnych_osob;
public:
    PrzyjscieKolejnychOsobDoTegoSamegoStolika(ObslugaZamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob) :AkcjaKontynuacyjna(obsluga_zamowienia)
    {
        this -> ilosc_kolejnych_osob = ilosc_kolejnych_osob;
    }
    void wykonaj_akcje()
    {
        cout << "Do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " przyszły " << ilosc_kolejnych_osob << " osob. "<<endl;
        obsluga_zamowienia.dodaj_nowe_osoby(ilosc_kolejnych_osob);
        cout << "Teraz łącznie przy stoliku jest " << obsluga_zamowienia.daj_ilosc_osob_przy_stoliku();
    }
};



class OdebranieZamowieniaOdStolika: public AkcjaKontynuacyjna // to sie bedzie wykonywalo wiele razy
{
    Potrawa* potrawa; // tu jest wskaznik bo potrawa ma rozne rodzaje
    unsigned int ilosc_sztuk;
public:
    OdebranieZamowieniaOdStolika(ObslugaZamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk): AkcjaKontynuacyjna(obsluga_zamowienia)
    {
        this -> potrawa = potrawa;
        this -> ilosc_sztuk = ilosc_sztuk;
    }

    void wykonaj_akcje()
    {
        cout << "Kelner " << obsluga_zamowienia.daj_kelnera().daj_imie() << " przyjmuje zamowienie dla stolika numer " << obsluga_zamowienia.daj_stolik().daj_numer();
        obsluga_zamowienia.zamow_potrawe(potrawa, ilosc_sztuk);
    }
};

class CzekanieNaPrzyniesienieDan: public AkcjaKontynuacyjna
{
public:
    CzekanieNaPrzyniesienieDan(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Czdkanie na przyniesienie dan przez kelnerad dla stolika nr."<< obsluga_zamowienia.daj_stolik().daj_numer();
    }
};

class PodanieDanDoStolika: public AkcjaKontynuacyjna
{

public:
    PodanieDanDoStolika(ObslugaZamowienia obsluga_zamowienia) : AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Dania do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " zostało przyniesionych przez kelnera " << obsluga_zamowienia.daj_kelnera().daj_imie() << "."<<endl;
        obsluga_zamowienia.podaj_dania_do_stolika();
    }
};


class TrwaJedzeniePosilku: public AkcjaKontynuacyjna
{

public:
    TrwaJedzeniePosilku(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Przy stoliku nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " jedzenie posiłku trwa ... czasu";
    }
};



class ZakonczenieWszystkichPosilkow : public AkcjaKontynuacyjna
{
public:
    ZakonczenieWszystkichPosilkow(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        obsluga_zamowienia.zakoncz_wszystkie_posilki();
        cout << "Klienci przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer() << "zakonczyli jedzenie posilku";
    }

};
class CzekanieNaRachunek: public AkcjaKontynuacyjna
{
public:
    CzekanieNaRachunek(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout << "Czekanie na rachunek przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer();
    }

};

class PodanieRachunkuKlientomPrzezKelnera: public AkcjaKontynuacyjna
{
public:
    PodanieRachunkuKlientomPrzezKelnera(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        Rachunek rachunek;
        rachunek = obsluga_zamowienia.stworz_rachunek();
        rachunek.wyswietl();
        obsluga_zamowienia.czekanie_na_zaplate();
    }

};

class ZaplataRachunku: public AkcjaKontynuacyjna
{

public:
    ZaplataRachunku(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        obsluga_zamowienia.zaplac();
        cout<< "Zamowienie zostalo uregulowane przy stoliku nr. "<<  obsluga_zamowienia.daj_stolik().daj_numer()<<endl;
    }

};

class WyjscieZRestauracji: public AkcjaKontynuacyjna
{
public:
    WyjscieZRestauracji(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Klienci ze stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " juz wyszli"<< endl;
        //save do pliku do acrchiwalnych danych
    }

};

class PrzygotowanieStoluDlaNowychKlientow: public AkcjaKontynuacyjna
{
public:
    PrzygotowanieStoluDlaNowychKlientow(ObslugaZamowienia Obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout << "Zaczeto sprzatac ze stolika nr." << obsluga_zamowienia.daj_stolik().daj_numer() << endl;
        obsluga_zamowienia.sprzatnij_ze_stolika();
    }
};
