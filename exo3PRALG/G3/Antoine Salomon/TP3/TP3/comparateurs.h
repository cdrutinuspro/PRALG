#pragma once

#include "Eleve.h"

class CompareNom {
public:
    int* ptr;
    CompareNom(int* p = 0);
    bool operator()(const Eleve& e1, const Eleve& e2);
};

class CompareNote {
public:
    int* ptr;
    CompareNote(int* p = 0);
    bool operator()(const Eleve& e1, const Eleve& e2);
};
