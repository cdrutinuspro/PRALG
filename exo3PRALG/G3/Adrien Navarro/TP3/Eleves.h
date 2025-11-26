#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <vector>
#include <iostream>

class Eleve {
public:
    std::string nom;
    int note;

    Eleve(std::string n, int nt) : nom(n), note(nt) {}
};

class CompareNom {
public:
    int* ptr;

    CompareNom(int* p) : ptr(p) {}

    bool operator()(Eleve a, Eleve b) {
        ++(*ptr);
        return a.nom < b.nom;
    }
};

class CompareNote {
public:
    int* ptr;

    CompareNote(int* p) : ptr(p) {}

    bool operator()(Eleve a, Eleve b) {
        ++(*ptr);
        return a.note > b.note;
    }
};

void afficher(std::vector<Eleve> v);

#endif
