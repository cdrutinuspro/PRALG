#include "Comparateurs.h"

CompareNom::CompareNom(int* p) {
    ptr = p;
}

bool CompareNom::operator()(const Eleve& e1, const Eleve& e2) {
    if (ptr != 0) {
        (*ptr)++;
    }
    return e1.getNom() < e2.getNom();
}

CompareNote::CompareNote(int* p) {
    ptr = p;
}

bool CompareNote::operator()(const Eleve& e1, const Eleve& e2) {
    if (ptr != 0) {
        (*ptr)++;
    }
    return e1.getNote() > e2.getNote();
}
