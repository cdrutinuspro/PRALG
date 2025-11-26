#include "Comparators.h"

CompareNom::CompareNom() : ptr(nullptr) {}

CompareNom::CompareNom(int* compteur) : ptr(compteur) {}

bool CompareNom::operator()(const Eleve& e1, const Eleve& e2) const {
    if (ptr != nullptr) {
        ++(*ptr);
    }
    return e1.getNom() < e2.getNom();
}


CompareNote::CompareNote() : ptr(nullptr) {}

CompareNote::CompareNote(int* compteur) : ptr(compteur) {}

bool CompareNote::operator()(const Eleve& e1, const Eleve& e2) const {

    if (ptr != nullptr) {
        ++(*ptr);
    }

    return e1.getNote() > e2.getNote();
}
