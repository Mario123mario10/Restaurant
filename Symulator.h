#include <memory>
using std::unique_ptr;

#include "Restauracja.h"



class Symulator
{
  private:
    unique_ptr<Restauracja> restauracja;
    unsigned int licznik_czasu;
  public:
    Symulator
    (
      unsigned int czas_trwania_symulacji,
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
    void inicjuj_restauracje();
    void losuj_dane_początkowe();
    void losuj_wydarzenia();
    void losuj_kelnera();
    void losuj_kucharza();
    void losuj_klienta();
    void losuj_danie();
};