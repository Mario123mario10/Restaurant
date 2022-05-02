#include <fstream>
using std::ios; using std::fstream; using std::getline;
#include <memory>
using std::unique_ptr ;
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <string>
using std::string;

#include "Restauracja.h"

class ObslugaWejsciowa
{
  private:
    unique_ptr<Restauracja> restauracja; //
    fstream plik;
    string sciezka;
  public:
    ObslugaWejsciowa(string sciezka);
    // ObslugaWejsciowa(string sciezka, string nazwa_pliku_wyjscia)
    void pobierz_linie();

};


