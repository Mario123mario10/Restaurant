
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
  cout << kelner << endl;
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
  cout << stolik << endl;

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
  cout << zamowienie << endl;

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

ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kwota kwota)
{
  cout << kwota << endl;
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
