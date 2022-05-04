
#include <memory>
using std::unique_ptr;  using std::make_unique;

#include <iostream>
using std::cin;  using std::cout;	using std::cerr;	using std::endl;
using std::getline;
#include <regex>
using std::regex;  using std::smatch;
using std::regex_search;  using std::regex_match;

using std::regex_constants::ECMAScript; using std::regex_constants::icase;
// ECMAScript | icase

#include "Interfejs.hpp"
#include "CiepłeNapoje.hpp"
#include "DanieMięsne.hpp"
#include "DanieWegetariańskie.hpp"
#include "Deser.hpp"
#include "Przystawka.hpp"
#include "Zupa.hpp"
#include "ZimneNapoje.hpp"
#include "CiepłeNapoje.hpp"
#include "wyjątki.hpp"

using std::move;
using std::stoul;


regex POMOC(" *pomoc *");
regex KONIEC(" *zamknij *");
regex POLICZ_CENY(" *policz +ceny *");
regex POLICZ_PRIORYTETY(" *policz +priorytety *");
regex WYSWIETL_MENU(" *wyświetl *");
regex DODAJ(" *dodaj +(przystawka|zupa|danie mięsne|danie wegetariańskie|deser|zimny napój|ciepły napój) +(.+) +(\\d+) *");
regex SKASUJ(" *skasuj +(przystawka|zupa|danie mięsne|danie wegetariańskie|deser|zimny napój|ciepły napój) +(.+) *");
regex CZYSC(" *(wy)?czyść *");


Interfejs::Interfejs()
{
  menu = make_unique<Menu>();
  cout << "Obsługa menu rozpoczęta" << endl;
  czy_dziala = true;
  while (czy_dziala)
  {
    try
    { pobierz_komende() ;}
    catch(const NiepoprawnaNazwa& e)
    { cerr << e.what() << endl ;}
    catch(const NiepoprawnyKoszt& e)
    { cerr << e.what() << endl ;}
    catch(const DanieJuzIstnieje& e)
    { cerr << e.what() << endl ;}
    catch(const DanieNieIstnieje& e)
    { cerr << e.what() << endl ;}
    catch(const std::exception& e)
    { cerr << "Błąd niestandardowy: " << endl << e.what() << endl ;}
  }

}

void Interfejs::pobierz_komende()
{
  string komenda;
  smatch typ;

  cout << "Proszę podać polecenie" << endl;
  getline(cin, komenda);

  if (regex_match(komenda, POLICZ_CENY))
  {
    menu -> policz_ceny();
    for (string nazwa_cena: menu -> daj_ceny())
    { cout << nazwa_cena << endl ;}
  }

  else if (regex_match(komenda, POLICZ_PRIORYTETY))
  {
    menu -> policz_priorytety();
    for (string nazwa_priorytet: menu -> daj_priorytety())
    { cout << nazwa_priorytet << endl ;}
  }

  else if (regex_match(komenda, WYSWIETL_MENU))
  { menu -> wyswietl_menu() ;}

  else if (regex_match(komenda, CZYSC))
  { menu -> wyczysc_menu() ;}

  else if (regex_match(komenda, typ, DODAJ))
  {
    if (typ[1] == "przystawka")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Przystawka>(typ[2], stoul(typ[3]));
      menu -> dodaj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "zupa")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Zupa>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "danie mięsne")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<DanieMiesne>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "danie wegetariańskie")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<DanieWegetarianskie>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "deser")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Deser>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "ciepły napój")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<CieplyNapoj>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }
    else
    {
      unique_ptr<Danie> tworzone_danie = make_unique<ZimnyNapoj>(typ[2], stoul(typ[3])) ;
      menu -> dodaj_danie(move(tworzone_danie));
    }



  //   menu -> dodaj_danie
  //   (
  //     move
  //     (
  //       utworz_danie(typ[1], typ[2], std::stoul(typ[3]))
  //     )
  //   );
  }

  else if (regex_match(komenda, typ, SKASUJ))
  {
    if (typ[1] == "przystawka")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Przystawka>(typ[2], 1);
      menu -> kasuj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "zupa")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Zupa>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "danie mięsne")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<DanieMiesne>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "danie wegetariańskie")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<DanieWegetarianskie>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "deser")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<Deser>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }

    else if (typ[1] == "ciepły napój")
    {
      unique_ptr<Danie> tworzone_danie = make_unique<CieplyNapoj>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }
    else
    {
      unique_ptr<Danie> tworzone_danie = make_unique<ZimnyNapoj>(typ[2], 1) ;
      menu -> kasuj_danie(move(tworzone_danie));
    }
    // menu -> kasuj_danie()
    // (
    //   move
    //   (
    //     utworz_danie
    //     (
    //       typ[1], typ[2], std::stoul(typ[3])
    //     )
    //   )
    // );
  }

  else if (regex_match(komenda, KONIEC))
  { zakoncz() ;}

  else if (regex_match(komenda, POMOC))
  { pomoc() ;}

  else
  { cout << "Nie rozpoznano polecenia" << endl ;}

}

unique_ptr<Danie> Interfejs::utworz_danie(string typ, string nazwa, unsigned int koszt)
{
  if (typ == "przystawka")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<Przystawka>(nazwa, koszt);
    return move(tworzone_danie);
  }

  else if (typ == "zupa")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<Zupa>(nazwa, koszt) ;
    return move(tworzone_danie);
  }

  else if (typ == "danie mięsne")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<DanieMiesne>(nazwa, koszt) ;
    return move(tworzone_danie);
  }

  else if (typ == "danie wegetariańskie")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<DanieWegetarianskie>(nazwa, koszt) ;
    return move(tworzone_danie);
  }

  else if (typ == "deser")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<Deser>(nazwa, koszt) ;
    return move(tworzone_danie);
  }

  else if (typ == "ciepły napój")
  {
    unique_ptr<Danie> tworzone_danie = make_unique<CieplyNapoj>(nazwa, koszt) ;
    return move(tworzone_danie);
  }
  else
  {
    unique_ptr<Danie> tworzone_danie = make_unique<ZimnyNapoj>(nazwa, koszt) ;
    return move(tworzone_danie);
  }
  // return move(tworzone_danie);
}

void Interfejs::pomoc()
{
  cout
  << "Interfejs menu udostępnia następujące polecenia:"
  << endl
  << "pomoc ==> wyświetla te wiadomości"
  << endl
  << "zamknij ==> kończy działanie interfejsu"
  << endl
  << "policz ceny ==> liczy i wyświetla ceny poszczególnych wpisów w menu"
  << endl
  << "policz priorytety ==> liczy i wyświetla priorytety poszczególnych wpisów w menu"
  << endl
  << "wyświetl ==> wyświetla całe menu"
  << endl
  << "dodaj (typ dania) (nazwa dania) (koszt przygotowania) ==> dodaje danie do menu"
  << endl
  << "skasuj (typ dania) (nazwa dania) ==> kasuje podane danie "
  << endl;
}



void Interfejs::zakoncz()
{
  czy_dziala = false;
  cout << "Wyłączam interfejs" << endl;
}