#include <string>
using std::string;

#include <iostream>
using std::cout;        using std::cerr;        using std::endl;

#include <memory>
using std::unique_ptr ;

#include <stdexcept>
using std::invalid_argument;


class NieZnalezionoPliku: public invalid_argument
{
  public:
    NieZnalezionoPliku(string zla_sciezka);
};

class NieprawidlowaKonfiguracja: public invalid_argument
{
  public:
    NieprawidlowaKonfiguracja(string komunikat);
};

