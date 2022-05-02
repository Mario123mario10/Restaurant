#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ios; using std::fstream; using std::getline;
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include "ObsługaWejściowa.h"



ObslugaWejsciowa::ObslugaWejsciowa(string sciezka)
{
  plik.open(sciezka, ios::in);
    if (plik.is_open())
    {
      while (not plik.eof())
      { pobierz_linie() ;}
      plik.close();
    }
    else
    {
      // throw
    }
}

void ObslugaWejsciowa::pobierz_linie()
{}