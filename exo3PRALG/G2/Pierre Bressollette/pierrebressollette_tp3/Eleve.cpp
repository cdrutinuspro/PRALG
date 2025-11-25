#include <iostream>
#include "Eleve.h"
using namespace std;

// Constructeur Eleve et méthodes

Eleve::Eleve(const string& nom, int note) : nom(nom), note(note) {};

string Eleve::getNom() const {
    return nom;
}

int Eleve::getNote() const {
    return note;
}

void Eleve::setNote(int n) {
    note = n;
}

// Comparaison suivant les champs de Eleve 

CompareNom::CompareNom(int* p) : ptr(p) {}

bool CompareNom::operator()(const Eleve& a, const Eleve& b) const {
    ++(*ptr);
    return a.getNom() < b.getNom();
}

CompareNote::CompareNote(int* p) : ptr(p) {}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const {
    ++(*ptr);
    return a.getNote() > b.getNote();
}

