#include "../Danie.hpp"
// Dania/poddania/deser/Deser.hpp
// Dania/Danie.hpp
class Deser: public Danie
{
  static unsigned int licznik_dan;
  public:
    Deser(string nazwa, Kwota koszt_przygotowania);
    friend std::ostream&  operator<<(std::ostream& os, Deser& Danie);

};

