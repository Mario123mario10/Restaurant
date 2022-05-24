// #ifndef PRACOWNIK_H
// #define PRACOWNIK_H
// #include <iostream>
// #include <string>
// using namespace std;
// // #include "czas_i_grafik.h"

// const int ilosc_dni = 25;



// class Pracownik
// {
//     string imie;
//     string nazwisko;

// public:
//     Pracownik(string imie, string nazwisko);

//     virtual int obliczanie_wynagrodzenia() const= 0; //metody czysto wirtualne (z =0) bo sie zmieniają w podklasach
//     virtual void wyswietl_grafik() const= 0;
//     string get_imie() const; //taka sama dla wszysktkich podklas
//     string get_nazwisko() const;

//     Pracownik(const Pracownik& other) = default;
//     Pracownik(Pracownik&& other);

//     Pracownik& operator=(const Pracownik& other)= default;

//     Pracownik& operator=(Pracownik&& other)= default;

//     ~Pracownik() = default;
// };

// class Kelner: public Pracownik
// {
//     int napiwki_za_godzine;
//     int stawka_godzinowa;
//     Czas godzina_poczatkowa;
//     Czas godzina_koncowa;
//     int kara_dzienna;

//     public:
//     Kelner(string imie, string nazwisko, Czas godzina_poczatkowa, Czas godzina_koncowa, int stawka_godzinowa, int kara_dzienna, int napiwki_za_godzine) : Pracownik(imie, nazwisko)
//     {
//         this -> godzina_poczatkowa = godzina_poczatkowa;
//         this -> godzina_koncowa = godzina_koncowa;
//         this -> stawka_godzinowa = stawka_godzinowa;
//         this -> kara_dzienna = kara_dzienna;
//         this -> napiwki_za_godzine = napiwki_za_godzine;
//     }
//     Czas get_godzina_poczatkowa() const
//     {
//         return godzina_poczatkowa;
//     }
//     Czas get_godzina_koncowa() const
//     {
//         return godzina_koncowa;
//     }
//     int get_stawka_godzinowa() const
//     {
//         return stawka_godzinowa;
//     }
//     int get_kara_dzienna() const
//     {
//         return kara_dzienna;
//     }
//     int get_napiwki_za_godzine() const
//     {
//         return napiwki_za_godzine;
//     }
//     int obliczanie_wynagrodzenia() const
//     {
//         return ((godzina_koncowa.get_godzina() - godzina_poczatkowa.get_godzina() + (godzina_koncowa.get_minuty() - godzina_poczatkowa.get_minuty()) / 60.0) * (stawka_godzinowa + napiwki_za_godzine) - kara_dzienna) * ilosc_dni;
//     }
//     void wyswietl_grafik() const
//     {
//         cout << "Twoje godziny pracy od poniedzialku do piatku od godziny ";
//         godzina_poczatkowa.wypisz();
//         cout << " do godziny ";
//         godzina_koncowa.wypisz();
//         cout <<endl;
//     }

// };
// class Kucharz: public Pracownik
// {
//     Czas godzina_poczatkowa;
//     Czas godzina_koncowa;
//     int stawka_godzinowa;
// public:
//     Kucharz(string imie, string nazwisko, Czas godzina_poczatkowa, Czas godzina_koncowa, int stawka_godzinowa) : Pracownik(imie, nazwisko)
//     {
//         this -> godzina_koncowa = godzina_koncowa;
//         this -> godzina_poczatkowa = godzina_poczatkowa;
//         this -> stawka_godzinowa = stawka_godzinowa;
//     }
//     Czas get_godzina_poczatkowa() const
//     {
//         return godzina_poczatkowa;
//     }
//     Czas get_godzina_koncowa() const
//     {
//         return godzina_koncowa;
//     }
//     int get_stawka_godzinowa() const
//     {
//         return stawka_godzinowa;
//     }
//     int obliczanie_wynagrodzenia() const
//     {
//         return (godzina_koncowa.get_godzina() - godzina_poczatkowa.get_godzina() + (godzina_koncowa.get_minuty() - godzina_poczatkowa.get_minuty())/60.0 ) * stawka_godzinowa * ilosc_dni;
//     }
//     void wyswietl_grafik() const
//     {
//         cout<< "Twoje godziny pracy od poniedzialku do piatku od godziny ";
//         godzina_poczatkowa.wypisz();
//         cout << " do godziny ";
//         godzina_koncowa.wypisz();
//         cout<<endl;
//     }

// };

// class Kierownik: public Pracownik
// {
//     int pensja_dzienna;
//     int premia;
// public:
//     Kierownik(string imie, string nazwisko, int pensja_dzienna, int premia): Pracownik(imie, nazwisko)
//     {
//         this -> pensja_dzienna = pensja_dzienna;
//         this -> premia = premia;
//     }
//     int get_pensja_dzienna() const
//     {
//         return pensja_dzienna;
//     }
//     int get_premia() const
//     {
//         return premia;
//     }
//     int obliczanie_wynagrodzenia() const
//     {
//         return pensja_dzienna * ilosc_dni + premia;
//     }
//     void wyswietl_grafik() const
//     {
//         cout << "Twoje godziny pracy sa dowolne" << endl;
//     }

// };


// class Pomocnik_kucharza: public Pracownik
// {
//     Czas godzina_poczatkowa;
//     Czas godzina_koncowa;
//     int pensja_dzienna;
// public:
//     Pomocnik_kucharza(string imie, string nazwisko, Czas godzina_poczatkowa, Czas godzina_koncowa, int pensja_dzienna): Pracownik(imie, nazwisko)
//     {
//         this -> pensja_dzienna = pensja_dzienna;
//         this -> godzina_koncowa = godzina_koncowa;
//         this -> godzina_poczatkowa = godzina_poczatkowa;
//     }
//     Czas get_godzina_poczatkowa() const
//     {
//         return godzina_poczatkowa;
//     }
//     Czas get_godzina_koncowa() const
//     {
//         return godzina_koncowa;
//     }
//     int get_pensja_dzienna() const
//     {
//         return pensja_dzienna;
//     }
//     int obliczanie_wynagrodzenia() const
//     {
//         return pensja_dzienna * ilosc_dni;
//     }
//     void wyswietl_grafik() const
//     {
//         cout << "Twoje godziny pracy od poniedzialku do piatku od godziny ";
//         godzina_poczatkowa.wypisz();
//         cout << " do godziny ";
//         godzina_koncowa.wypisz();
//         cout<<endl;
//     }


// };

// class Dostawca: public Pracownik
// {
//     Grafik grafik;
//     int stawka_za_dostawe_raz_na_godzine;
//     int pensja_stala_za_miesiac;
// public:
//     Dostawca(string imie, string nazwisko, Grafik grafik, int stawka_za_dostawe_raz_na_godzine, int pensja_stala_za_miesiac): Pracownik(imie, nazwisko)
//     {
//         this -> grafik = grafik;
//         this -> stawka_za_dostawe_raz_na_godzine = stawka_za_dostawe_raz_na_godzine;
//         this -> pensja_stala_za_miesiac = pensja_stala_za_miesiac;
//     }
//     int get_stawka_za_dostawe_raz_na_godzine()
//     {
//         return stawka_za_dostawe_raz_na_godzine;
//     }
//     int get_pensja_stala_za_miesiac()
//     {
//         return pensja_stala_za_miesiac;
//     }
//     int obliczanie_wynagrodzenia() const
//     {
//         return grafik.laczna_liczba_godzin() * stawka_za_dostawe_raz_na_godzine * 4 + pensja_stala_za_miesiac;
//     }
//     Grafik get_grafik() const
//     {
//         return grafik;
//     }
//     void wyswietl_grafik() const
//     {
//         grafik.wyswietl();
//     }

// };

// #endif