#include <iostream>
using std::cout;	using std::cerr;	using std::endl;
#include <chrono>
#include <random>
#include "FunkcjePomocnicze.h"

template<typename Typ>
void drukuj(Typ cos)
{ cout << cos << endl ;}

template<typename Typ>
void drukuj_bl(Typ cos)
{ cerr << cos << endl ;}

