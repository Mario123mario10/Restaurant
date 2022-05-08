#include "DanieGłówne.hpp"

DanieGlowne::DanieGlowne
(string nazwa, unsigned int koszt_przygotowania, unsigned int czas_przygotowania):
  Danie(nazwa, koszt_przygotowania, czas_przygotowania, KategoriaPotrawy::DANIE_GLOWNE) {}
