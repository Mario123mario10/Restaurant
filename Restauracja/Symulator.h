#include <memory>
using std::unique_ptr;

#include "Restauracja.h"
#include "../Menu/Menu.hpp"


class Symulator
{
  private:
    Restauracja restauracja;
    unique_ptr<Menu> menu;
    unsigned int czas_trwania_symulacji;

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
      unsigned int liczba_kelnerow,
      unique_ptr<Menu> menu
    );
    void rozpocznij_symulacje();
    void losuj_kelnera();
    void losuj_klientow();
    void losuj_klienta();
    string losuj_nazwisko();
    static unsigned int losuj_liczbe();
    unsigned int daj_czas_trwania_symulacji();

};
