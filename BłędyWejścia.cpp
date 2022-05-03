#include <stdexcept>
using std::invalid_argument;

#include <string>
using std::string;

#include <iostream>
using std::cout;        using std::cerr;        using std::endl;

#include "BłędyWejścia.h"

using std::to_string;


NieZnalezionoPliku::NieZnalezionoPliku(string zla_sciezka):
invalid_argument("Nie znaleziono pliku o podanej scieżce: " + zla_sciezka){}

NieprawidlowaKonfiguracja::NieprawidlowaKonfiguracja(string komunikat):
invalid_argument(komunikat) {}
