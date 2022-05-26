#include "ObsługaZamówienia.h"
#include "../Kelner/Kelner.h"
#include "Akcja.h"

Akcja::~Akcja()
{}

AkcjaInicjacyjna::AkcjaInicjacyjna(Stolik stolik, unsigned int ilosc_osob)
{
    this -> ilosc_osob = ilosc_osob;
    this -> stolik = stolik;
}

void AkcjaInicjacyjna::wykonaj_akcje()
{
    ObslugaZamowienia zamowienie(stolik, ilosc_osob);
}


AkcjaKontynuacyjna::AkcjaKontynuacyjna(ObslugaZamowienia obsluga_zamowienie)
{
    this -> obsluga_zamowienia = obsluga_zamowienia;
}



    // Obsluga_zamowienia stolik z ludxmi

Akcja_zanies_menu::Akcja_zanies_menu(ObslugaZamowienia obsluga_zamowienia, Kelner kelner): AkcjaKontynuacyjna(obsluga_zamowienia)
{
    this -> kelner = kelner;
}
void Akcja_zanies_menu::wykonaj_akcje()
{
    obsluga_zamowienia.przypisz_kelnera_i_zanies_menu(kelner);
}


// kiedy kelner patrzy czy juz mozna pobrac od nich dania i podchodzi kiedy juz stwierdzi ze juz dokonali wyboru

RozwazanieWyboruDan::RozwazanieWyboruDan(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void RozwazanieWyboruDan::wykonaj_akcje()
{
    cout<< "Zastanawianie sie klientow nad wyborem posilkow przy stole "<< obsluga_zamowienia.daj_stolik().daj_numer();
}


PrzyjscieKolejnychOsobDoTegoSamegoStolika::PrzyjscieKolejnychOsobDoTegoSamegoStolika(ObslugaZamowienia obsluga_zamowienia, unsigned int ilosc_kolejnych_osob) :AkcjaKontynuacyjna(obsluga_zamowienia)
{
    this -> ilosc_kolejnych_osob = ilosc_kolejnych_osob;
}
void PrzyjscieKolejnychOsobDoTegoSamegoStolika::wykonaj_akcje()
{
    cout << "Do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " przyszły " << ilosc_kolejnych_osob << " osob. "<<endl;
    obsluga_zamowienia.dodaj_nowe_osoby(ilosc_kolejnych_osob);
    cout << "Teraz łącznie przy stoliku jest " << obsluga_zamowienia.daj_ilosc_osob_przy_stoliku();
}




OdebranieZamowieniaOdStolika::OdebranieZamowieniaOdStolika(ObslugaZamowienia obsluga_zamowienia, Potrawa* potrawa, unsigned int ilosc_sztuk): AkcjaKontynuacyjna(obsluga_zamowienia)
{
    this -> potrawa = potrawa;
    this -> ilosc_sztuk = ilosc_sztuk;
}

void OdebranieZamowieniaOdStolika::wykonaj_akcje()
{
    cout << "Kelner " << obsluga_zamowienia.daj_kelnera().daj_imie() << " przyjmuje zamowienie dla stolika numer " << obsluga_zamowienia.daj_stolik().daj_numer();
    obsluga_zamowienia.zamow_potrawe(potrawa, ilosc_sztuk);
}

CzekanieNaPrzyniesienieDan::CzekanieNaPrzyniesienieDan(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void CzekanieNaPrzyniesienieDan::wykonaj_akcje()
{
    cout<< "Czdkanie na przyniesienie dan przez kelnerad dla stolika nr."<< obsluga_zamowienia.daj_stolik().daj_numer();
}


PodanieDanDoStolika::PodanieDanDoStolika(ObslugaZamowienia obsluga_zamowienia) : AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void PodanieDanDoStolika::wykonaj_akcje()
{
    cout<< "Dania do stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " zostało przyniesionych przez kelnera " << obsluga_zamowienia.daj_kelnera().daj_imie() << "."<<endl;
    obsluga_zamowienia.podaj_dania_do_stolika();
}



TrwaJedzeniePosilku::TrwaJedzeniePosilku(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void TrwaJedzeniePosilku::wykonaj_akcje()
{
    cout<< "Przy stoliku nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " jedzenie posiłku trwa ... czasu";
}



ZakonczenieWszystkichPosilkow::ZakonczenieWszystkichPosilkow(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void ZakonczenieWszystkichPosilkow::wykonaj_akcje()
{
    obsluga_zamowienia.zakoncz_wszystkie_posilki();
    cout << "Klienci przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer() << "zakonczyli jedzenie posilku";
}


CzekanieNaRachunek::CzekanieNaRachunek(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void CzekanieNaRachunek::wykonaj_akcje()
{
    cout << "Czekanie na rachunek przy stole numer" << obsluga_zamowienia.daj_stolik().daj_numer();
}


PodanieRachunkuKlientomPrzezKelnera::PodanieRachunkuKlientomPrzezKelnera(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void PodanieRachunkuKlientomPrzezKelnera::wykonaj_akcje()
{
    Rachunek rachunek;
    rachunek = obsluga_zamowienia.stworz_rachunek();
    rachunek.wyswietl();
    obsluga_zamowienia.czekanie_na_zaplate();
}


ZaplataRachunku::ZaplataRachunku(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void ZaplataRachunku::wykonaj_akcje()
{
    obsluga_zamowienia.zaplac();
    cout<< "Zamowienie zostalo uregulowane przy stoliku nr. "<<  obsluga_zamowienia.daj_stolik().daj_numer()<<endl;
}


WyjscieZRestauracji::WyjscieZRestauracji(ObslugaZamowienia obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void WyjscieZRestauracji::wykonaj_akcje()
{
    cout<< "Klienci ze stolika nr. " << obsluga_zamowienia.daj_stolik().daj_numer() << " juz wyszli"<< endl;
    //save do pliku do acrchiwalnych danych
}


PrzygotowanieStoluDlaNowychKlientow::PrzygotowanieStoluDlaNowychKlientow(ObslugaZamowienia Obsluga_zamowienia): AkcjaKontynuacyjna(obsluga_zamowienia)
{}

void PrzygotowanieStoluDlaNowychKlientow::wykonaj_akcje()
{
    cout << "Zaczeto sprzatac ze stolika nr." << obsluga_zamowienia.daj_stolik().daj_numer() << endl;
    obsluga_zamowienia.sprzatnij_ze_stolika();
}
