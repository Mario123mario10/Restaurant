#include <string>
using std::string;

class Klient
{
  private:
    string imie;
    bool dosiada_sie;
    unsigned int identyfikator;
  public:
    Klient(string imie, bool dosiada_sie, unsigned int identyfikator);
    bool czy_dosiada_sie();
    string daj_imie();
    unsigned int daj_identyfikator();
    friend std::ostream& operator<<(std::ostream& os, Klient& klient);
};
