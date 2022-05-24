#pragma once


class Restauracja
{
  // private:
  //   string nazwa;
  public:
    Restauracja();
    Restauracja(
      string nazwa,
      unsigned int rozmiar_maly,
      unsigned int rozmiar_sredni,
      unsigned int rozmiar_duzy,
      unsigned int male,
      unsigned int sredni,
      unsigned int duze
    );
    void tiktok();
    void dodaj_klienta();

};