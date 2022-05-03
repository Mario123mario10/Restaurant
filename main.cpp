#pragma only
#include "BłędyWejścia.h"
#include "ObsługaWejściowa.h"
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
      ObslugaWejsciowa O(argv[1]);
      Symulator S(
        O.daj_czas_symulacji(),
        O.daj_nazwe_restauracji(),
        O.daj_rozmiar_maly(),
        O.daj_rozmiar_sredni(),
        O.daj_rozmiar_duzy(),
        O.daj_male_stoliki(),
        O.daj_srednie_stoliki(),
        O.daj_duze_stoliki()
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
