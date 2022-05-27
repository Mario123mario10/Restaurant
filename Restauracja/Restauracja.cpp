#include <vector>
#include <iostream>
using std::cout;	using std::endl;

#include "../Akcje/ObsługaZamówienia.h"
#include "Restauracja.h"


Restauracja::Restauracja()
{}


Restauracja::Restauracja(string nazwa, string nazwa_pliku_wyjscia)
{
  this -> nazwa = nazwa;
  this -> wyjscie = ObslugaWyjsciowa(nazwa_pliku_wyjscia);
}



// void Restauracja::uplyw_czasu()
// {

// }

void Restauracja::pokaz_status_kelnerow()
{
  for (Kelner kelner: kelnerzy)
  {
    if (not kelner.czy_zajety())
    {
      wyjscie << kelner;
      wyjscie << "\n";
    }
  }
}

void Restauracja::pokaz_status_klientow()
{
  for (unique_ptr<Klient>& klient: nieobslugiwani_klienci)
  {
    wyjscie << *klient;  //pomyśleć
    wyjscie <<  "\n";
  }
}

void Restauracja::pokaz_status_zamowien()
{
  for (ObslugaZamowienia zamowienie: zamowienia_aktualne)
  {
    wyjscie << zamowienie;
    wyjscie << "\n";
  }
}

void Restauracja::pokaz_status_stolikow()
{
  for (Stolik stolik: stoliki)
  {
    wyjscie << stolik;
    wyjscie << "\n";
  }
}

void Restauracja::dodaj_klienta(unique_ptr<Klient> wchodzacy_klient)
{
  nieobslugiwani_klienci.push_back(wchodzacy_klient);
}

void Restauracja::dodaj_kelnera(Kelner kelner)
{
  this -> kelnerzy.push_back(kelner);
}

void Restauracja::dodaj_stolik(Stolik stolik)
{
  this -> stoliki.push_back(stolik);
}

void Restauracja::sprawdz_klientow()
{

}

void Restauracja::sprawdz_stoliki()
{

}

void Restauracja::sprawdz_kelnerow()
{

}

void Restauracja::zwolnij_stoliki()
{

}

void Restauracja::zwolnij_kelnerow()
{

}

void Restauracja::zwolnij_zamowienia()
{

}


void Restauracja::stworz_zamowienie(unique_ptr<Klient> klient, unique_ptr<Stolik> stolik)
{

}

void Restauracja::przydziel_klienta()
{

}

void Restauracja::dodaj_zamowienie(unique_ptr<Klient> klient, Stolik& stolik)
{


}





// void Restauracja::dodaj_zamowienie(ObslugaZamowienia zamowienie)
// {
//   zamowienia_aktualne.push_back(zamowienie);
// }

// void Restauracja::zamknij_zamowienie(ObslugaZamowienia zamowienie)
// {
//   zamowienia_aktualne.erase(zamowienia_aktualne.index(zamowienie));
//   zamowienia_zamkniete.push_back(zamowienie);
// }

// ObslugaZamowienia Restauracja::daj_zamowienie(int index)
// {
//   return zamowienia_aktualne[index];

// }
// vector <Stolik> Restauracja::daj_wolne_stoliki()
// {
//   vector <Stolik> wolne_stoliki;
//   for (const Stolik& stolik: wolne_stoliki)
//   {
//       if (stolik.czy_wolny() == true)
//       {
//           wolne_stoliki.push_back(stolik);
//       }
//   }
//   return wolne_stoliki;
// }

// Kelner Restauracja::daj_kelnera(unsigned int index)
// {
//   return kelnerzy[index];
// }

// Danie* Restauracja::daj_potrawe(unsigned int numer)  // wszystko co ma rodzaje i ma podklasy ma wskaźniki
// {
//   return menu.daj_potrawe();
// }

// Menu Restauracja::daj_menu()
// {
//   return menu;
// }
// unsigned int Restauracja::daj_ilosc_aktualnych_zamowien()
// {
//   return zamowienia_aktualne.size();
// }
