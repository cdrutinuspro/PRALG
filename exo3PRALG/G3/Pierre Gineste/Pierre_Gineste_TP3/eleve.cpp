#include "eleve.h"
#include <cstdlib>
#include <ctime>
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
    std::cout << std::setw(15) << std::left << nom
              << " : " << std::setw(2) << std::right << note << "/20"
              << std::endl;
}

Eleve Eleve::genererAleatoire() {
    std::string nom_genere;

    nom_genere += char('A' + rand() % 26);

    int longueur = 1 + rand() % 10;

    for (int i = 0; i < longueur; i++) {
        nom_genere += char('a' + rand() % 26);
    }

    int note_generee = rand() % 21;

    return Eleve(nom_genere, note_generee);
}

std::ostream& operator<<(std::ostream& os, const Eleve& eleve) {
    os << std::setw(15) << std::left << eleve.getNom()
    << " : " << std::setw(2) << std::right << eleve.getNote() << "/20";
    return os;
}
