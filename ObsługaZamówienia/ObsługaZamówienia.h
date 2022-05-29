#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
using std::unique_ptr ;

#include "../Dania/Danie.hpp"
#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "../Klient/Klient.h"

enum class StatusZamowienia
{
    oczekiwanie_na_menu,
    zamawianie_dan,
    oczekiwanie_na_dania,
    jedzenie,
    czekanie_na_rachunek,
    placenie,
    wyjscie_z_restauracji,
    sprzatanie_stolika
};

using SZ = StatusZamowienia;

#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <fstream>
#include <memory>
using std::unique_ptr ; using std::make_unique;
#include <vector>
#include <string>
using std::string;

using std::vector;
using namespace std;


// class A
// {
// 	private:
// 		bool prawda;
// 	public:
// 		A()
// 		{ 	prawda = false;	};
// 		bool daj_prawde()
// 		{	return prawda;	};
// 		void ustaw_prawde(bool co)
// 		{	prawda = co;	};
// };

// class B
// {
// 	public:
// 		unique_ptr<A> moje_a;
// 		B(unique_ptr<A> obiekt)
// 		{
// 			moje_a.swap(obiekt);
// 		};

// 		unique_ptr<A> daj_A()
// 		{
// 			unique_ptr<A> wsk;
// 			moje_a.swap(wsk);
// 			return wsk;
// 		};

//         bool czy_przydzielony()
//         { return moje_a == nullptr;  };

// };


// int main()
// {
// 	unique_ptr<A> klasaA= make_unique<A>();
// 	klasaA -> ustaw_prawde(true);
// 	B obiektB(move(klasaA));
// 	unique_ptr<A> wsk = obiektB.daj_A();
// 	cout << (wsk -> daj_prawde()) << endl;
//     cout << obiektB.czy_przydzielony() << endl;
// }




class ObslugaZamowienia
{
    vector<unique_ptr<Klient>> klienci;
    unique_ptr<Stolik> przypisany_stolik;
    unique_ptr<Kelner> przypisany_kelner;
    StatusZamowienia status;
    unsigned int numer_zamowienia;
    unsigned int licznik_zamowien;

public:
    vector<unique_ptr<Danie>> zamowione_dania;
    ObslugaZamowienia();
    ObslugaZamowienia(unique_ptr<Stolik> stolik, unique_ptr<Klient> klient);
    StatusZamowienia daj_status();
    unsigned int daj_numer_zamowienia();
    unsigned int daj_ilosc_osob_przy_stoliku();
    unsigned int daj_numer_stolika();
    string daj_nazwisko_kelnera();

    unique_ptr<Stolik> zwolnij_stolik();
    unique_ptr<Kelner> zwolnij_kelnera();

    void wyswietl_klientow(fstream& plik);

    bool jest_kelner();

    void zaplac();
    void sprzatnij_ze_stolika();
    void czekanie_na_zaplate();
    void zakoncz_wszystkie_posilki();
    void zamow_potrawe(unique_ptr<Danie> nowa_potrawa, unsigned int ilosc_sztuk);
    unsigned int oblicz_kwote_do_zaplaty();

    void uplyw_czasu();

    friend std::ostream& operator<<(std::ostream& os, ObslugaZamowienia& zamowienie);

};

