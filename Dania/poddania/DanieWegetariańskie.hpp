#include "DanieGłówne.hpp"



class DanieWegetarianskie: public DanieGlowne
{
  static unsigned int licznik_dan;

  public:
    DanieWegetarianskie
    (
      string nazwa,
      Kwota koszt_przygotowania
    );

    friend std::ostream&  operator<<(std::ostream& os, DanieWegetarianskie& Danie);

};
