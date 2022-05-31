#include <string>
using std::string;

#include "catch.hpp"
#include "../Kelner.h"


using std::move;

TEST_CASE("Ustawianie i sprawdzanie atrybutow kelnera", "[Kelner]")
{

  Kelner kelner;
  kelner.ustaw_imie("Jan");
  kelner.ustaw_id(1);
  kelner.ustaw_zajety(false);

  CHECK(kelner.daj_imie() == "Jan");
  CHECK(kelner.daj_id() == 1);
  CHECK(kelner.daj_zajety = false);

}