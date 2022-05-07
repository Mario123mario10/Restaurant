#pragma once
#include <string>
using std::string;

enum class KategoriaPotrawy
{
  NAPOJ = 1,
  PRZYSTAWKA = 1,
  DESER,
  DANIE_GLOWNE,
  SUMA = NAPOJ + PRZYSTAWKA + DANIE_GLOWNE + DESER
};

class Danie
{
  private:
    KategoriaPotrawy kategoria            ;
    unsigned int        koszt_przygotowania  ;
    unsigned int        czas_przygotowania   ;
    unsigned int        czas_oczekiwania     ;
    string              nazwa                ;
    bool                przygotowane         ;
    unsigned int        postep_przygotowania ;

  public:
    Danie
    (
      string nazwa,
      unsigned int koszt_przygotowania,
      unsigned int czas_przygotowania,
      KategoriaPotrawy kategoria
    );
    virtual ~Danie();
    virtual bool operator== (Danie& inne_Danie);
    virtual bool operator!= (Danie& inne_Danie);

    KategoriaPotrawy daj_kategorie();
    unsigned int        daj_koszt_przygotowania();
    unsigned int        daj_czas_przygotowania();
    unsigned int        daj_czas_oczekiwania();
    unsigned int        daj_postep_przygotowania();
    string              daj_nazwe();
    bool                czy_przygotowane();

    virtual void ustaw_kategorie(KategoriaPotrawy nowa_kategoria);
    virtual void ustaw_koszt_przygotowania(unsigned int nowy_koszt_przygotowania);
    virtual void ustaw_czas_przygotowania(unsigned int nowy_czas_przygotowania);
    virtual void ustaw_czas_oczekiwania(unsigned int new_czas_oczekiwania);
    virtual void ustaw_postep_przygotowania(unsigned int nowy_postep_przygotowania);
    virtual void ustaw_czy_przygotowane(bool nowy_status);
    virtual void ustaw_nazwe(string nowa_nazwa);

    virtual unsigned int  policz_cene(float modyfikator = 1);
    virtual int           policz_priorytet(int modyfikator = 0);
    virtual void          przygotowuj();
    virtual void          wyswietl();

};





