#include <memory>
using std::unique_ptr;

#include "Restauracja.h"



class Symulator
{
  private:
    unique_ptr<Restauracja> restauracja;
    unsigned int czas_trwania_symulacji;
    unsigned int licznik_klientow;
    unsigned int licznik_kelnerow;
    unsigned int licznik_kucharzy;
    unsigned int licznik_potraw; // wyszczególnić
    unsigned int liczba_kucharzy;
    unsigned int liczba_kelnerow;

    // unsigned int identyfikator_dania;
  public:
    Symulator
    (
      unsigned int czas_trwania_symulacji,
      string nazwa_pliku_wyjscia,
      string nazwa_restauracji,
      unsigned int rozmiar_maly,
      unsigned int rozmiar_sredni,
      unsigned int rozmiar_duzy,
      unsigned int male,
      unsigned int srednie,
      unsigned int duze,
      unsigned int liczba_kucharzy,
      unsigned int liczba_kelnerow
    );
    void rozpocznij_sumulacje();
    void utworz_personel();
    void losuj_kelnera(unsigned int identyfikator);
    void losuj_kucharza(unsigned int identyfikator);
    void losuj_klientow();
    void losuj_klienta();
    void losuj_danie();
    unsigned int generuj_liczbe();
};