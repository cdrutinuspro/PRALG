#ifndef COMPARATORS_H
#define COMPARATORS_H

#include "eleve.h"

class CompareNom {
public:
    int* ptr;

    CompareNom();

    CompareNom(int* compteur);

    bool operator()(const Eleve& e1, const Eleve& e2) const;
};

class CompareNote {
public:
    int* ptr;

    CompareNote();

    CompareNote(int* compteur);

    bool operator()(const Eleve& e1, const Eleve& e2) const;
};

#endif
