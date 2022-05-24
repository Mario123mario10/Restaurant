
#include "Napój.hpp"


Napoj::Napoj(string nazwa, Kwota koszt_przygotowania, unsigned int czas_przygotowania):
  Danie(nazwa, koszt_przygotowania, czas_przygotowania, KategoriaPotrawy::NAPOJ) {}
