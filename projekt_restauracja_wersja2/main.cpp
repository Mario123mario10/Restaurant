#include "Symulacja_restauracji.h"
#include "Restauracja.h"


int main()
{
    Restauracja r1;
    Symulacja_restauracji s1(r1);
    s1.startuj();
}

// w main najlepiej byloby gdyby tylko to zostalo i nie bylo kelnerow utworzonych na poczatku