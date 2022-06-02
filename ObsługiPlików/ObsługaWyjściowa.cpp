
#include <string>
using std::string;
#include <fstream>
using std::ios; using std::fstream;
#include "../Błędy.h"


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
  { throw NiepoprawnaNazwa(nowa_nazwa); }

}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kelner& kelner)
{
  fstream plik;
  cout << kelner;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << kelner;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }
  plik.close();
  return wyjscie;
}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Stolik& stolik)
{
  fstream plik;
  cout << stolik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << stolik;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }

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
    plik << zamowienie;
    plik.close();
    return wyjscie;
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }


}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kwota kwota)
{
  cout << kwota;
  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << kwota;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }


  return wyjscie;

}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, string napis)
{
  cout << napis;
  fstream plik;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << napis;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }

  plik.close();

  return wyjscie;
}


ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Klient& kelner)
{
  fstream plik;
  cout << kelner;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << kelner;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }

  return wyjscie;
}

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Danie& danie)
{
    fstream plik;
  cout << danie;
  plik.open(wyjscie.daj_nazwe_pliku_wyjscia(), ios::out | ios::app);
  if (plik.is_open())
  {
    plik << danie;
    plik.close();
  }
  else
  { throw NieZnalezionoPliku(wyjscie.daj_nazwe_pliku_wyjscia()); }

  return wyjscie;

}

