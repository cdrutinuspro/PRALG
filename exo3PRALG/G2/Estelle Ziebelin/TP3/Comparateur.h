#pragma once
#include "Eleve.h"

struct CompareNom {
    int* ptr;
    CompareNom() : ptr(nullptr) {}
    CompareNom(int* p) : ptr(p) {}

    bool operator()(const Eleve& e1, const Eleve& e2) {
        if (ptr) ++(*ptr);
        return e1.get_nom() < e2.get_nom();
    }
};

struct CompareNote {
    int* ptr;
    CompareNote() : ptr(nullptr) {}
    CompareNote(int* p) : ptr(p) {}

    bool operator()(const Eleve& e1, const Eleve& e2) {
        if (ptr) ++(*ptr);
        return e1.get_note() > e2.get_note();
    }
};
