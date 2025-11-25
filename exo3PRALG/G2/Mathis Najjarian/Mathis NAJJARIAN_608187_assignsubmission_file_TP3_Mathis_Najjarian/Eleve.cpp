#include "Eleve.h"

Eleve::Eleve(std::string nom, int note)
    : nom(std::move(nom)), note(note)
{
}