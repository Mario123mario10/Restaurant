#pragma only

#include <memory>
using std::unique_ptr;
using std::make_unique;

#include "BłędyWejścia.h"
#include "ObsługaWejściowa.h"
#include "ObsługaWyjściowa.h"
#include "Funkcje_pomocnicze.cpp"
#include "Symulator.h"

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    drukuj_bl("Zbyt mało argumentów");
    return 1;
  }
  else
  {
    try
    {
      ObslugaWejsciowa We(argv[1]);
      // ObslugaWyjsciowa Wy();
      Symulator S(
        We.daj_czas_symulacji(),
        We.daj_nazwe_pliku_wyjscia(),
        We.daj_nazwe_restauracji(),
        We.daj_rozmiar_maly(),
        We.daj_rozmiar_sredni(),
        We.daj_rozmiar_duzy(),
        We.daj_male_stoliki(),
        We.daj_srednie_stoliki(),
        We.daj_duze_stoliki(),
        We.daj_liczbe_kucharzy(),
        We.daj_liczbe_kelnerow()
      );

    }
    catch(const NieZnalezionoPliku& blad)
    {
      drukuj_bl(blad.what());
      return 1;
    }
    catch(const NieprawidlowaKonfiguracja& blad)
    {
      drukuj_bl(blad.what());
      return 1;
    }

  return 0;
  }
}
