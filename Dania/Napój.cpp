
#include "Napój.hpp"


Napoj::Napoj(string nazwa, unsigned int koszt_przygotowania, unsigned int czas_przygotowania):
  Danie(nazwa, koszt_przygotowania, czas_przygotowania, BazaKategoriiPotraw::NAPOJ) {}
