#include "Obsluga_zamowienia.h"
using namespace std;
#include "Akcja.h"
#include "Restauracja.h"


Akcja_inicjacyjna::Akcja_inicjacyjna(Stolik stolik, unsigned int ilosc_osob, Restauracja restauracja)
{
    this -> ilosc_osob = ilosc_osob;
    this -> stolik = stolik;
    this -> restauracja = restauracja;
}

void Akcja_inicjacyjna::wykonaj_akcje()
{
    Obsluga_zamowienia zamowienie(stolik, ilosc_osob);
    restauracja.dodaj_zamowienie(zamowienie);
}





Akcja_kontynuacyjna::Akcja_kontynuacyjna(Obsluga_zamowienia obsluga_zamowienie)
{
    this -> obsluga_zamowienia = obsluga_zamowienia;
}





Akcja_zanies_menu::Akcja_zanies_menu(Obsluga_zamowienia obsluga_zamowienia, Kelner kelner): Akcja_kontynuacyjna(obsluga_zamowienia)
{
    this -> kelner = kelner;
}
void Akcja_zanies_menu::wykonaj_akcje()
{
    obsluga_zamowienia.przypisz_kelnera_i_zanies_menu(kelner);
}



Zastanawianie_sie_nad_wyborem_dan::Zastanawianie_sie_nad_wyborem_dan(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Zastanawianie_sie_nad_wyborem_dan::wykonaj_akcje()
{
    cout<< "Zastanawianie sie klientow nad wyborem posilkow przy stole "<< obsluga_zamowienia.daj_stolik().daj_numer();
}



Przyjscie_kolejnych_osob_do_tego_samego_stolika::Przyjscie_kolejnych_osob_do_tego_samego_stolika(Obsluga_zamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob) :Akcja_kontynuacyjna(obsluga_zamowienia)
{
    this -> ilosc_kolejnych_osob = ilosc_kolejnych_osob;
}
void Przyjscie_kolejnych_osob_do_tego_samego_stolika::wykonaj_akcje()
{
    cout << "Do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " przyszły " << ilosc_kolejnych_osob << " osob. "<<endl;
    obsluga_zamowienia.dodaj_nowe_osoby(ilosc_kolejnych_osob);
    cout << "Teraz łącznie przy stoliku jest " << obsluga_zamowienia.daj_ilosc_osob_przy_stoliku();
}





Odebranie_zamowienia_od_stolika::Odebranie_zamowienia_od_stolika(Obsluga_zamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk): Akcja_kontynuacyjna(obsluga_zamowienia)
{
    this -> potrawa = potrawa;
    this -> ilosc_sztuk = ilosc_sztuk;
}

void Odebranie_zamowienia_od_stolika::wykonaj_akcje()
{
    cout << "Kelner " << obsluga_zamowienia.daj_kelnera().daj_imie() << " przyjmuje zamowienie dla stolika numer " << obsluga_zamowienia.daj_stolik().daj_numer();
    obsluga_zamowienia.zamow_potrawe(potrawa, ilosc_sztuk);
}



Czekanie_na_przyniesienie_dan::Czekanie_na_przyniesienie_dan(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Czekanie_na_przyniesienie_dan::wykonaj_akcje()
{
    cout<< "Czekanie na przyniesienie dan przez kelnerad dla stolika nr."<< obsluga_zamowienia.daj_stolik().daj_numer();
}



Podanie_dan_do_stolika::Podanie_dan_do_stolika(Obsluga_zamowienia obsluga_zamowienia) : Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Podanie_dan_do_stolika::wykonaj_akcje()
{
    cout<< "Dania do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " zostało przyniesionych przez kelnera " << obsluga_zamowienia.daj_kelnera().daj_imie() << "."<<endl;
    obsluga_zamowienia.podaj_dania_do_stolika();
}






Trwa_jedzenie_posilku::Trwa_jedzenie_posilku(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Trwa_jedzenie_posilku::wykonaj_akcje()
{
    cout<< "Przy stoliku nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " jedzenie posiłku trwa ... czasu";
}




Zakonczenie_wszystkich_posilkow::Zakonczenie_wszystkich_posilkow(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Zakonczenie_wszystkich_posilkow::wykonaj_akcje()
{
    obsluga_zamowienia.zakoncz_wszystkie_posilki();
    cout << "Klienci przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer() << "zakonczyli jedzenie posilku";
}

Czekanie_na_rachunek::Czekanie_na_rachunek(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Czekanie_na_rachunek::wykonaj_akcje()
{
    cout << "Czekanie na rachunek przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer();
}

Podanie_rachunku_klientom_przez_kelnera::Podanie_rachunku_klientom_przez_kelnera(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Podanie_rachunku_klientom_przez_kelnera::wykonaj_akcje()
{
    Rachunek rachunek;
    rachunek = obsluga_zamowienia.stworz_rachunek();
    rachunek.wyswietl();
    obsluga_zamowienia.czekanie_na_zaplate();
}



Zaplata_rachunku::Zaplata_rachunku(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void  Zaplata_rachunku::wykonaj_akcje()
{
    obsluga_zamowienia.zaplac();
    cout<< "Zamowienie zostalo uregulowane przy stoliku nr. "<<  obsluga_zamowienia.daj_stolik().daj_numer()<<endl;

}



Wyjscie_z_restauracji::Wyjscie_z_restauracji(Obsluga_zamowienia obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Wyjscie_z_restauracji::wykonaj_akcje()
{
    cout<< "Klienci ze stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " juz wyszli"<< endl;
    //save do pliku do acrchiwalnych danych
}



Przygotowanie_stolu_dla_nowych_klientow::Przygotowanie_stolu_dla_nowych_klientow(Obsluga_zamowienia Obsluga_zamowienia): Akcja_kontynuacyjna(obsluga_zamowienia)
{}

void Przygotowanie_stolu_dla_nowych_klientow::wykonaj_akcje()
{
    cout << "Zaczeto sprzatac ze stolika nr." << obsluga_zamowienia.daj_stolik().daj_numer() << endl;
    obsluga_zamowienia.sprzatnij_ze_stolika();
}




