#include <regex>
using std::regex;  using std::smatch;  using std::regex_search;  using std::regex_match;


// Linie wczytywania pliku
const regex L_NAZWA_RESTAURACJI   (" *\t*nazwa *\t*restauracji *\t*(.+) *\t*");
const regex L_CZAS_TRWANIA        (" *\t*czas *\t*trwania *\t*(\\d+) *\t*");
const regex L_R_MALYCH_STOLIKOW   (" *\t*mały: *\t*(\\d+) *\t*");
const regex L_R_SREDNICH_STOLIKOW (" *\t*średni: *\t*(\\d+) *\t*");
const regex L_R_DUZYCH_STOLIKOW   (" *\t*duży: *\t*(\\d+) *\t*");
const regex L_L_MALYCH_STOLIKOW   (" *\t*stoliki *\t*małe *\t*(\\d+) *\t*");
const regex L_L_SREDNICH_STOLIKOW (" *\t*stoliki *\t*średnie *\t*(\\d+) *\t*");
const regex L_L_DUZYCH_STOLIKOW   (" *\t*stoliki *\t*duże *\t*(\\d+) *\t*");
const regex L_L_KELNEROW          (" *\t*liczba *\t*kelnerów: *\t*(\\d+) *\t*");
const regex L_L_KUCHARZY          (" *\t*liczba *\t*kucharzy: *\t*(\\d+) *\t*");
