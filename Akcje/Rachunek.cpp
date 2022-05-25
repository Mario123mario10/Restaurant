#include <vector>
using std::vector;

#include "Rachunek.h"


Rachunek::Rachunek()
{
    czy_rachunek_zaplacony = false;
}
void Rachunek::wyswietl()
{

}
void Rachunek::zaplac()
{
    czy_rachunek_zaplacony = true;
}
