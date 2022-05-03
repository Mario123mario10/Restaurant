#include "BłędyWejścia.h"
#include "ObsługaWejściowa.h"
#include "Funkcje_pomocnicze.cpp"


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
