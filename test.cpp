// #include <fstream>
// using std::ios; using std::fstream; using std::getline;
// #include <iostream>
// using std::cout;	using std::cerr;	using std::endl;
// #include <string>
// using std::string;
// #include <memory>
// using std::unique_ptr ; using std::make_unique;
// #include <chrono>
// #include <random>
// #include <thread>
// #include "Kwota.h"
// #include <stdexcept>
// using std::invalid_argument;
// using std::to_string;


// class NiepoprawnaKwota: public invalid_argument
// {
//   public:
//     NiepoprawnaKwota(Kwota zla_kwota);
//     NiepoprawnaKwota(int zla_wartosc);

// };


// NiepoprawnaKwota::NiepoprawnaKwota(Kwota zla_kwota):
// invalid_argument("Zła kwota: " + (string) zla_kwota) {}

// NiepoprawnaKwota::NiepoprawnaKwota(int zla_wartosc):
// invalid_argument("Nie da się ustawić tej wartości: " + to_string(zla_wartosc)) {}


// int main()
// {

//   // unsigned int nasiono = std::chrono::system_clock::now().time_since_epoch().count();
//   // std::mt19937 generator(nasiono);

//   // for (int i=0; i<10; ++i)
//   // {
//   //   std::cout << generator() << " ";
//   // }
//   // std::this_thread::sleep_for(std::chrono::seconds(0));
//   // cout << "Kys" << endl;
//   // std::this_thread::sleep_for(std::chrono::seconds(1));
//   // cout << "Kys" << endl;
//   // std::cout << std::endl;
// //   unique_ptr<ZimnyNapoj> przystawka = make_unique<ZimnyNapoj>(nazwa, Kwota(zlote, grosze));
// //   Kwota k(120, 12);
// //   cout << k << endl;
//   // cout << (-112 % 100) << endl;
//   return 0;
// }
