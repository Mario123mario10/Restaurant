
#include <string>
using std::string;
#include <fstream>
using std::ios; using std::fstream;


#include "ObsługaWyjściowa.h"

ObslugaWyjsciowa::ObslugaWyjsciowa()
{}


ObslugaWyjsciowa::ObslugaWyjsciowa(string nazwa_pliku_wyjscia)
{
  this -> nazwa_pliku_wyjscia = nazwa_pliku_wyjscia;
}

string ObslugaWyjsciowa::daj_nazwe_pliku_wyjscia()
{ return nazwa_pliku_wyjscia  ;}


void ObslugaWyjsciowa::ustaw_nazwe_pliku_wyjscia(string nowa_nazwa)
{
  if (not nowa_nazwa.empty())
  { nazwa_pliku_wyjscia = nowa_nazwa  ;}
  else
  { } // rzuć wyjątek
}



ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kelner& kelner)
{
  cout << kelner;
  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {

  }
  else
  { } // rzuć wyjątek

  plik.close();

  return wyjscie;
}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Stolik& stolik)
{
  cout << stolik;

  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {

  }
  else
  { } // rzuć wyjątek

  plik.close();

  return wyjscie;

}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, ObslugaZamowienia& zamowienie)
{
  cout << zamowienie;

  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik
    << "Status zamówienia nr " << zamowienie.daj_numer_zamowienia()
    << " i stole nr " << zamowienie.daj_numer_stolika()
    << ":" << endl;

//   switch(zamowienie.daj_status())
//   {
//     case SZ::oczekiwanie_na_menu:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "czekają na menu";
//       return os;

//     case SZ::zamawianie_dan:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "zamawiają dania";
//       return os;

//     case SZ::oczekiwanie_na_dania:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os
//       << "Oczekują na dania" << endl
//       << "Postęp w przygotowaniu dań:" << endl;
//       for ( const unique_ptr<Danie>& danie: zamowienie.zamowione_dania  )
//       { cout << *danie << endl  ;}
//       return os;

//     case SZ::jedzenie:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "Spożywają posiłek";
//       return os;

//     case SZ::czekanie_na_rachunek:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "Czekają na rachunek";
//       return os;

//     // case SZ::czekanie_kelnera_na_zaplate:

//     //   return os;

//     case SZ::placenie:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "Płacą za jedzenie: " << zamowienie.oblicz_kwote_do_zaplaty();
//       return os;

//     case SZ::wyjscie_z_restauracji:
//       os << "Klienci:" << endl;
//       for (unique_ptr<Klient>& klient: zamowienie.klienci)
//       { os << *klient << endl; }
//       os << "Wychodzą z restauracji";
//       return os;

//     case SZ::sprzatanie_stolika:
//       os << "Klienci " << endl;

//       return os;
//   }
//   return os;
// }













    plik.close();
  }
  else
  { } // rzuć wyjątek

  plik.close();
  return wyjscie;

}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kwota kwota)
{
  cout << kwota;
  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {


    plik.close();
  }
  else
  { } // rzuć wyjątek


  return wyjscie;

}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, string napis)
{
  cout << napis;
  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {

    plik.close();
  }
  else
  { } // rzuć wyjątek

  plik.close();

  return wyjscie;
}
