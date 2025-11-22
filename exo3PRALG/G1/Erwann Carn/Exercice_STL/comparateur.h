#pragma once
#include "eleve.h"

struct CompareNom{
    int *ptr = nullptr;
    bool operator()(const Eleve& a, const Eleve& b) const{
        if (ptr)++ *ptr;
        return (a.getNom() < b.getNom());
    }
};

struct CompareNote{
    int* ptr = nullptr;
    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++*ptr;
        if (a.getNote() != b.getNote()) return a.getNote() > b.getNote(); // décroissant
        return a.getNom() < b.getNom();
    }
};
