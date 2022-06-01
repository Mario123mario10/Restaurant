#include <regex>
using std::regex;


// przerwa ==  *
// nazwa   == (.+)
// liczba  == (\\d+)



// Linie pliku konfiguracyjnego
const regex L_NAZWA_PLIKU_WYJSCIA (" *zapisz *do: *(.+) *");
const regex L_NAZWA_PLIKU_MENU    (" *ścieżka *menu: *(.+) *");
const regex L_NAZWA_RESTAURACJI   (" *nazwa *restauracji: *(.+) *");
const regex L_CZAS_TRWANIA        (" *czas *trwania: *(\\d+) *");
const regex L_CZAS_RAPORTOWANIA   (" *czas *raportowania: *(\\d+) *");
const regex L_R_MALYCH_STOLIKOW   (" *mały: *(\\d+) *");
const regex L_R_SREDNICH_STOLIKOW (" *średni: *(\\d+) *");
const regex L_R_DUZYCH_STOLIKOW   (" *duży: *(\\d+) *");
const regex L_L_MALYCH_STOLIKOW   (" *stoliki *małe: *(\\d+) *");
const regex L_L_SREDNICH_STOLIKOW (" *stoliki *średnie: *(\\d+) *");
const regex L_L_DUZYCH_STOLIKOW   (" *stoliki *duże: *(\\d+) *");
const regex L_L_KELNEROW          (" *liczba *kelnerów: *(\\d+) *");
// Linie menu
const regex L_M_PRZYSTAWKA        (" *P *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_ZUPA              (" *Z *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_DANIE_MIESNE      (" *M *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_DANIE_WEGE        (" *W *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_DESER             (" *D *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_NAPOJ_CIEPLY      (" *Z *(.+) *(\\d+) *zł *(\\d+) *gr *");
const regex L_M_NAPOJ_ZIMNY       (" *C *(.+) *(\\d+) *zł *(\\d+) *gr *");

// Stałe symulacji
const unsigned int MAX_NOWYCH_KLIENTOW = 8;
const unsigned int ILOSC_NAZWISK = 95;
const unsigned int SZANSA_NA_POZOSTANIE = 2;
const unsigned int SZANSA_NA_BRAK_KLIENTOW = 2;
