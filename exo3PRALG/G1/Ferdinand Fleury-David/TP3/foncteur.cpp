#include "foncteur.h"

CompareNom::CompareNom(int* p) : ptr(p) {}
CompareNote::CompareNote(int* p) : ptr(p) {}

bool CompareNom::operator ()(const Eleve& a, const Eleve& b) const{
    if (ptr) ++(*ptr);
    return a.getNom()<b.getNom();
}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const{
    if (ptr) ++(*ptr);
    return a.getMoyenne()>b.getMoyenne();
}
