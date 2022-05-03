#include <memory>
using std::unique_ptr ;

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
      unsigned int duze
    );

};