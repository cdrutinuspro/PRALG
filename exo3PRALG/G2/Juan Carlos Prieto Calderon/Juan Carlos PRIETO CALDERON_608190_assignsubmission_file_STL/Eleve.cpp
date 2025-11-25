#include "Eleve.h"
#include <stdexcept>

// Getter for note
int Eleve::getNote() const noexcept {
    return note;
}

// Getter for nom
std::string Eleve::getNom() const noexcept {
    return nom;
}

// Setter for note
void Eleve::setNote(int note) {
    if (note < 0 || note > 20) {
        throw std::invalid_argument("Note must be between 0 and 20.");
    }
    this->note = note;
}

// Setter for nom
void Eleve::setNom(const std::string& nom) {
    if (nom.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }
    else if (nom.length() > 11) {
        throw std::invalid_argument("Name is too long.");
    }
    else if (nom[0] < 'A' || nom[0] > 'Z') {
        throw std::invalid_argument("Name must start with a capital letter.");
    }
    this->nom = nom;
}