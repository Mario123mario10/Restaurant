#include <regex>
using std::regex;

// przerwa == [ \\t]*
// nazwa   == (.+)
// liczba  == (\\d+)



// Linie pliku konfiguracyjnego
const regex L_NAZWA_PLIKU_WYJSCIA ("[ \\t]*zapisz[ \\t]*do:[ \\t]*(.+)[ \\t]*");
const regex L_NAZWA_PLIKU_MENU    ("[ \\t]*ścieżka[ \\t]*menu:[ \\t]*(.+)[ \\t]*");
const regex L_NAZWA_RESTAURACJI   ("[ \\t]*nazwa[ \\t]*restauracji[ \\t]*(.+)[ \\t]*");
const regex L_CZAS_TRWANIA        ("[ \\t]*czas[ \\t]*trwania[ \\t]*(\\d+)[ \\t]*");
const regex L_CZAS_RAPORTOWANIA   ("[ \\t]*czas[ \\t]*raportowania[ \\t]*(\\d+)[ \\t]*");
const regex L_R_MALYCH_STOLIKOW   ("[ \\t]*mały:[ \\t]*(\\d+)[ \\t]*");
const regex L_R_SREDNICH_STOLIKOW ("[ \\t]*średni:[ \\t]*(\\d+)[ \\t]*");
const regex L_R_DUZYCH_STOLIKOW   ("[ \\t]*duży:[ \\t]*(\\d+)[ \\t]*");
const regex L_L_MALYCH_STOLIKOW   ("[ \\t]*stoliki[ \\t]*małe[ \\t]*(\\d+)[ \\t]*");
const regex L_L_SREDNICH_STOLIKOW ("[ \\t]*stoliki[ \\t]*średnie[ \\t]*(\\d+)[ \\t]*");
const regex L_L_DUZYCH_STOLIKOW   ("[ \\t]*stoliki[ \\t]*duże[ \\t]*(\\d+)[ \\t]*");
const regex L_L_KELNEROW          ("[ \\t]*liczba[ \\t]*kelnerów:[ \\t]*(\\d+)[ \\t]*");
const regex L_L_KUCHARZY          ("[ \\t]*liczba[ \\t]*kucharzy:[ \\t]*(\\d+)[ \\t]*");
// Linie menu
const regex L_M_PRZYSTAWKA        ("[ \\t]*P[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_ZUPA              ("[ \\t]*Z[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_DANIE_MIESNE      ("[ \\t]*M[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_DANIE_WEGE        ("[ \\t]*W[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_DESER             ("[ \\t]*D[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_NAPOJ_CIEPLY      ("[ \\t]*Z[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");
const regex L_M_NAPOJ_ZIMNY       ("[ \\t]*C[ \\t]*(.+)[ \\t]*(\\d+)[ \\t]*");

