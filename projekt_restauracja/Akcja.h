#include "ObsługaZamówienia.h"

class Akcja
{
public:
    virtual void wykonaj_akcje() = 0;
};

class Akcja_inicjacyjna : public Akcja //podejscie kolejnych osob do stolika
{
    unsigned int ilosc_osob;
    Stolik stolik;
public:
    Akcja_inicjacyjna(Stolik stolik, unsigned int ilosc_osob)
    {
        this -> ilosc_osob = ilosc_osob;
        this -> stolik = stolik;
    }

    void wykonaj_akcje()
    {
        Obsluga_zamowienia zamowienie(stolik, ilosc_osob);
    }


};

class Akcja_kontynuacyjna : public Akcja  //dosiadanie się kolejnych osob do zajetego stolika
{
protected:
    Obsluga_zamowienia obsluga_zamowienia;
public:
    Akcja_kontynuacyjna(Obsluga_zamowienia obsluga_zamowienie)
    {
        this -> obsluga_zamowienia = obsluga_zamowienia;
    }
};


        // Obsluga_zamowienia stolik z ludxmi

class Akcja_zanies_menu: public Akcja_kontynuacyjna
{
    Kelner kelner;
public:
    Akcja_zanies_menu(Obsluga_zamowienia obsluga_zamowienia, Kelner kelner): Akcja_kontynuacyjna(obsluga_zamowienia)
    {
        this -> kelner = kelner;
    }
    void wykonaj_akcje()
    {
        obsluga_zamowienia.przypisz_kelnera_i_zanies_menu(kelner);
    }
};

// kiedy kelner patrzy czy juz mozna pobrac od nich dania i podchodzi kiedy juz stwierdzi ze juz dokonali wyboru
class Zastanawianie_sie_nad_wyborem_dan: public Akcja_kontynuacyjna
{
public:
    Zastanawianie_sie_nad_wyborem_dan(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Zastanawianie sie klientow nad wyborem posilkow przy stole "<< obsluga_zamowienia.daj_stolik().daj_numer();
    }
};

class Przyjscie_kolejnych_osob_do_tego_samego_stolika: public Akcja_kontynuacyjna
{
    unsigned int ilosc_kolejnych_osob;
public:
    Przyjscie_kolejnych_osob_do_tego_samego_stolika(Obsluga_zamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob) :Akcja_kontynuacyjna(obsluga_zamowienia)
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



class Odebranie_zamowienia_od_stolika: public Akcja_kontynuacyjna // to sie bedzie wykonywalo wiele razy
{
    Potrawa* potrawa; // tu jest wskaznik bo potrawa ma rozne rodzaje
    unsigned int ilosc_sztuk;
public:
    Odebranie_zamowienia_od_stolika(Obsluga_zamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk): Akcja_kontynuacyjna(obsluga_zamowienia)
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

class Czekanie_na_przyniesienie_dan: public Akcja_kontynuacyjna
{
public:
    Czekanie_na_przyniesienie_dan(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Czdkanie na przyniesienie dan przez kelnerad dla stolika nr."<< obsluga_zamowienia.daj_stolik().daj_numer();
    }
};

class Podanie_dan_do_stolika: public Akcja_kontynuacyjna
{

public:
    Podanie_dan_do_stolika(Obsluga_zamowienia obsluga_zamowienia) : Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Dania do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " zostało przyniesionych przez kelnera " << obsluga_zamowienia.daj_kelnera().daj_imie() << "."<<endl;
        obsluga_zamowienia.podaj_dania_do_stolika();
    }


};


class Trwa_jedzenie_posilku: public Akcja_kontynuacyjna
{

public:
    Trwa_jedzenie_posilku(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Przy stoliku nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " jedzenie posiłku trwa ... czasu";
    }

};



class Zakonczenie_wszystkich_posilkow : public Akcja_kontynuacyjna
{
public:
    Zakonczenie_wszystkich_posilkow(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        obsluga_zamowienia.zakoncz_wszystkie_posilki();
        cout << "Klienci przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer() << "zakonczyli jedzenie posilku";
    }

};
class Czekanie_na_rachunek: public Akcja_kontynuacyjna
{
public:
    Czekanie_na_rachunek(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout << "Czekanie na rachunek przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer();
    }

};

class Podanie_rachunku_klientom_przez_kelnera: public Akcja_kontynuacyjna
{
public:
    Podanie_rachunku_klientom_przez_kelnera(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        Rachunek rachunek;
        rachunek = obsluga_zamowienia.stworz_rachunek();
        rachunek.wyswietl();
        obsluga_zamowienia.czekanie_na_zaplate();
    }

};

class Zaplata_rachunku: public Akcja_kontynuacyjna
{

public:
    Zaplata_rachunku(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        obsluga_zamowienia.zaplac();
        cout<< "Zamowienie zostalo uregulowane przy stoliku nr. "<<  obsluga_zamowienia.daj_stolik().daj_numer()<<endl;

    }

};

class Wyjscie_z_restauracji: public Akcja_kontynuacyjna
{
public:
    Wyjscie_z_restauracji(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout<< "Klienci ze stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " juz wyszli"<< endl;
        //save do pliku do acrchiwalnych danych
    }

};

class Przygotowanie_stolu_dla_nowych_klientow: public Akcja_kontynuacyjna
{
public:
    Przygotowanie_stolu_dla_nowych_klientow(Obsluga_zamowienia Obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
    {}

    void wykonaj_akcje()
    {
        cout << "Zaczeto sprzatac ze stolika nr." << obsluga_zamowienia.daj_stolik().daj_numer() << endl;
        obsluga_zamowienia.sprzatnij_ze_stolika();
    }
};






