#include "Dania/Danie.hpp"
#include "Dania/poddania/CiepłeNapoje.hpp"
#include "Dania/poddania/ZimneNapoje.hpp"
#include "Dania/poddania/DanieMięsne.hpp"
#include "Dania/poddania/DanieGłówne.hpp"
#include "Dania/poddania/DanieWegetariańskie.hpp"
#include "Dania/poddania/Deser.hpp"
#include "Dania/poddania/Napój.hpp"
#include "Dania/poddania/Przystawka.hpp"
#include "Dania/poddania/Zupa.hpp"
#include "Stolik/Stolik.h"
#include "Klient/Klient.h"
#include "Kelner/Kelner.h"
#include "ObsługaZamówienia/ObsługaZamówienia.h"

// Liczniki obiektow
unsigned int Danie::licznik_dan = 0;
unsigned int CieplyNapoj::licznik_dan = 0;
unsigned int ZimnyNapoj::licznik_dan = 0;
unsigned int Zupa::licznik_dan = 0;
unsigned int Przystawka::licznik_dan = 0;
unsigned int Napoj::licznik_dan = 0;
unsigned int Deser::licznik_dan = 0;
unsigned int DanieWegetarianskie::licznik_dan = 0;
unsigned int DanieGlowne::licznik_dan = 0;
unsigned int Stolik::licznik_stolikow = 0;
unsigned int Klient::licznik_klientow = 0;
unsigned int Kelner::licznik_kelnerow = 0;
unsigned int ObslugaZamowienia::licznik_zamowien = 0;

