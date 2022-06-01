
#include <memory>
using std::unique_ptr;
using std::make_unique;

#include "Błędy.h"
#include "ObsługiPlików/ObsługaWejściowa.h"
#include "ObsługiPlików/ObsługaWyjściowa.h"
#include "FunkcjePomocnicze.cpp"
#include "Restauracja/Symulator.h"

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
      unique_ptr<Menu> zebrane_menu = make_unique<Menu>();
      zebrane_menu = We.menu.przekaz_dania(move(zebrane_menu));
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
        We.daj_liczbe_kelnerow(),
        We.daj_czas_raportowania(),
        move(zebrane_menu)
      );
    }
    catch(const NieZnalezionoPliku& blad)
    {
      drukuj_bl(blad.what());
      return 1;
    }
    catch(const NiepelnaKonfiguracja& blad)
    {
      drukuj_bl(blad.what());
      return 1;
    }
    catch(const NieprawidloweMenu& blad)
    {
      drukuj_bl(blad.what());
      return 1;
    }

    catch(const std::exception& e)
    {
      drukuj_bl("Błąd niestandardowy: ");
      drukuj_bl(e.what());
    }


  return 0;
  }
}
