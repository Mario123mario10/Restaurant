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
      unsigned int czas
    );



};