#include <string>
using std::string;

#include "Danie.h"
#include "Bledy.h"

using KP = KategoriaPotrawy;


Danie::Danie
(
	string nazwa,
	Kwota koszt_przygotowania,
	unsigned int czas_przygotowania,
	KategoriaPotrawy kategoria
)
{
	if (nazwa.empty())
	{	throw	NiepoprawnaNazwa(nazwa)	;}
	else if (koszt_przygotowania == 0)
	{ throw NiepoprawnyKoszt(koszt_przygotowania)	;}
	else if (czas_przygotowania == 0)
	{ throw NiepoprawnyCzasPrzygotowania(czas_przygotowania)	;}
	else
	{
    this -> kategoria = kategoria ;
    this -> koszt_przygotowania = koszt_przygotowania ;
    this -> czas_przygotowania = czas_przygotowania;
    this -> czas_oczekiwania = 0;
    this -> nazwa = nazwa;
    this -> przygotowane = false;
    this -> postep_przygotowania = 0;
	}
}

Danie::~Danie()
{}

KP Danie::daj_kategorie()
{ return kategoria;}

Kwota Danie::daj_koszt_przygotowania()
{ return koszt_przygotowania;}

unsigned int Danie::daj_czas_przygotowania()
{ return czas_przygotowania;}

unsigned int Danie::daj_czas_oczekiwania()
{	return czas_oczekiwania	;}

unsigned int Danie::daj_postep_przygotowania()
{ return postep_przygotowania	;}

string Danie::daj_nazwe()
{ return nazwa	;}

bool Danie::czy_przygotowane()
{ return przygotowane	;}

void Danie::ustaw_kategorie(KP nowa_kategoria)
{ kategoria = nowa_kategoria ;}

void Danie::ustaw_koszt_przygotowania(Kwota nowy_koszt_przygotowania)
{
	if (nowy_koszt_przygotowania == 0)
	{ throw	NiepoprawnyKoszt(nowy_koszt_przygotowania)	;}

	else
	{ koszt_przygotowania = nowy_koszt_przygotowania ;}
}

void Danie::ustaw_czas_przygotowania(unsigned int nowy_czas_przygotowania)
{
	if (nowy_czas_przygotowania == 0)
	{	throw NiepoprawnyCzasPrzygotowania(nowy_czas_przygotowania)	;}
	else
	{ czas_przygotowania = nowy_czas_przygotowania ;}
}

void Danie::ustaw_czas_oczekiwania(unsigned int nowy_czas_oczekiwania)
{ czas_oczekiwania = nowy_czas_oczekiwania ;}

void Danie::ustaw_postep_przygotowania(unsigned int nowy_postep_przygotowania)
{
  if (nowy_postep_przygotowania < czas_przygotowania)
  { postep_przygotowania = nowy_postep_przygotowania  ;}
  else
  // { throw NiepoprawnyPostepPrzygotowania(nowy_postep_przygotowania) ;}
	{}

}

void Danie::ustaw_czy_przygotowane(bool nowy_status)
{ przygotowane = nowy_status ;}

void Danie::ustaw_nazwe(string nowa_nazwa)
{
	if (not nowa_nazwa.empty())
	{	nazwa = nowa_nazwa	;}
	else
	// { throw NiepoprawnaNazwa(nowa_nazwa)  ;}
	{}

}

Kwota Danie::policz_cene()
{
	return (koszt_przygotowania + (static_cast<unsigned int>(kategoria) * czas_przygotowania));
}

int Danie::policz_priorytet()
{
	unsigned int priorytet_podstawowy = static_cast<unsigned int>(KP::SUMA) - static_cast<unsigned int>(kategoria);
	return priorytet_podstawowy + czas_oczekiwania - czas_przygotowania;
}

void Danie::przygotowuj()
{
	if (not przygotowane)
	{
		postep_przygotowania += 1;
		if (postep_przygotowania == czas_przygotowania)
		{ przygotowane = true	;}
	}
}

void Danie::wyswietl()
{}


bool Danie::operator== (Danie& inne_danie)
{
  return
  (
    inne_danie.daj_nazwe() == nazwa
    and
    inne_danie.daj_kategorie() == kategoria
  );

}

bool Danie::operator!= (Danie& inne_danie)
{ return not (*this == inne_danie)  ;}

