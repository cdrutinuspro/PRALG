#include "eleve.h"
#include <iostream>
#include <iomanip>


Eleve::Eleve() : nom(""), note(0) {}

Eleve::Eleve(const std::string& nom, int note) : nom(nom), note(note) {}


std::string Eleve::getNom() const {
    return nom;
}

int Eleve::getNote() const {
    return note;
}


void Eleve::setNom(const std::string& nom) {
    this->nom = nom;
}

void Eleve::setNote(int note) {
    this->note = note;
}


void Eleve::afficher() const {
    std::cout << std::left << std::setw(15) << nom
              << " Note: " << std::setw(2) << note << "/20" << std::endl;
}


bool CompareNom::operator()(const Eleve& e1, const Eleve& e2) {
    if (ptr_compteur != nullptr) {
        ++(*ptr_compteur);
    }
    return e1.getNom() < e2.getNom();
}


bool CompareNote::operator()(const Eleve& e1, const Eleve& e2) {
    if (ptr_compteur != nullptr) {
        ++(*ptr_compteur);
    }
    return e1.getNote() > e2.getNote();
}
