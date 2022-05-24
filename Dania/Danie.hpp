#pragma once
#include <string>
using std::string;

#include "../Kwota.h"

enum class KategoriaPotrawy
{
  NAPOJ = 1,
  PRZYSTAWKA,
  DESER,
  DANIE_GLOWNE,
  SUMA = NAPOJ + PRZYSTAWKA + DANIE_GLOWNE + DESER
};

class Danie
{
  private:
    KategoriaPotrawy    kategoria            ;
    string              nazwa                ;
    Kwota               koszt_przygotowania  ;
    unsigned int        czas_przygotowania   ;
    unsigned int        czas_oczekiwania     ;
    unsigned int        postep_przygotowania ;
    unsigned int        identyfikator        ;
    bool                przygotowane         ;

  public:
    Danie
    (
      string nazwa,
      Kwota koszt_przygotowania,
      unsigned int czas_przygotowania,
      KategoriaPotrawy kategoria
    );
    virtual ~Danie();
    virtual bool operator== (Danie& inne_Danie);
    virtual bool operator!= (Danie& inne_Danie);

    KategoriaPotrawy    daj_kategorie();
    Kwota               daj_koszt_przygotowania();
    unsigned int        daj_czas_przygotowania();
    unsigned int        daj_czas_oczekiwania();
    unsigned int        daj_postep_przygotowania();
    string              daj_nazwe();
    bool                czy_przygotowane();

    void ustaw_kategorie(KategoriaPotrawy nowa_kategoria);
    void ustaw_koszt_przygotowania(Kwota nowy_koszt_przygotowania);
    void ustaw_czas_przygotowania(unsigned int nowy_czas_przygotowania);
    void ustaw_czas_oczekiwania(unsigned int new_czas_oczekiwania);
    void ustaw_postep_przygotowania(unsigned int nowy_postep_przygotowania);
    void ustaw_czy_przygotowane(bool nowy_status);
    void ustaw_nazwe(string nowa_nazwa);

    virtual Kwota         policz_cene();
    virtual int           policz_priorytet();
    virtual void          przygotowuj();
    virtual void          wyswietl();
    friend std::ostream&  operator<<(std::ostream& os, Danie& Danie);
};





