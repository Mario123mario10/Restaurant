#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <chrono>
#include <random>
#include "Funkcje_pomocnicze.h"

template<typename Typ>
void drukuj(Typ cos)
{ cout << cos << endl ;}

template<typename Typ>
void drukuj_bl(Typ cos)
{ cerr << cos << endl ;}

unsigned int generuj_liczbe()
{
  unsigned int nasiono = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(nasiono);
  return generator();
}