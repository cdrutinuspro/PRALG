#pragma once
#include "eleve.h"

class CompareNom{
public:
    int* ptr;
    CompareNom(int* p= nullptr);
    bool operator()(const Eleve& a, const Eleve& b) const;
};

class CompareNote{
public:
    int* ptr;

    CompareNote(int* p = nullptr);
    bool operator()(const Eleve& a, const Eleve& b) const;
};


