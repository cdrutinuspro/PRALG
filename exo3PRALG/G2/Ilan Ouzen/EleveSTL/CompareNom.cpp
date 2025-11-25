#include "CompareNom.h"

CompareNom::CompareNom(int *c): ptr(c) {}

bool CompareNom::operator()(const Eleve&E1, const Eleve&E2) const {
        ++*ptr;
        return (E1.get_nom()<E2.get_nom());
    }
