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
// #include "Kwota/Kwota.h"
// #include <stdexcept>
// using std::invalid_argument;
// using std::to_string;
// #include <regex>
// using std::regex;  using std::smatch;  using std::regex_search;  using std::regex_match;

// // class NiepoprawnaKwota: public invalid_argument
// // {
// //   public:
// //     NiepoprawnaKwota(Kwota zla_kwota);
// //     NiepoprawnaKwota(int zla_wartosc);

// // };


// // NiepoprawnaKwota::NiepoprawnaKwota(Kwota zla_kwota):
// // invalid_argument("Zła kwota: " + (string) zla_kwota) {}

// // NiepoprawnaKwota::NiepoprawnaKwota(int zla_wartosc):
// // invalid_argument("Nie da się ustawić tej wartości: " + to_string(zla_wartosc)) {}

// // Linie pliku konfiguracyjnego
// const regex L_NAZWA_PLIKU_WYJSCIA (" *zapisz *do: *(.+) *");
// const regex L_NAZWA_PLIKU_MENU    (" *ścieżka *menu: *(.+) *");
// const regex L_NAZWA_RESTAURACJI   (" *nazwa *restauracji: *(.+) *");
// const regex L_CZAS_TRWANIA        (" *czas *trwania: *(\\d+) *");
// const regex L_CZAS_RAPORTOWANIA   (" *czas *raportowania: *(\\d+) *");
// const regex L_R_MALYCH_STOLIKOW   (" *mały: *(\\d+) *");
// const regex L_R_SREDNICH_STOLIKOW (" *średni: *(\\d+) *");
// const regex L_R_DUZYCH_STOLIKOW   (" *duży: *(\\d+) *");
// const regex L_L_MALYCH_STOLIKOW   (" *stoliki *małe: *(\\d+) *");
// const regex L_L_SREDNICH_STOLIKOW (" *stoliki *średnie: *(\\d+) *");
// const regex L_L_DUZYCH_STOLIKOW   (" *stoliki *duże: *(\\d+) *");
// const regex L_L_KELNEROW          (" *liczba *kelnerów: *(\\d+) *");
// // Linie menu
// const regex L_M_PRZYSTAWKA        (" *P *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_ZUPA              (" *Z *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_DANIE_MIESNE      (" *M *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_DANIE_WEGE        (" *W *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_DESER             (" *D *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_NAPOJ_CIEPLY      (" *Z *(.+) *(\\d+) *zł *(\\d+) *gr *");
// const regex L_M_NAPOJ_ZIMNY       (" *C *(.+) *(\\d+) *zł *(\\d+) *gr *");




// int main()
// {
//     fstream p;
//     p.open("pliki_konfiguracyjne/konfiguracja.txt", std::ios::in);
//     string linia;
//     std::smatch a;
//     getline(p, linia);
//     cout << regex_match(linia, a, L_CZAS_TRWANIA) << endl;
//     cout << a[1] << endl;
//     p.close();
//   return 0;
// }
