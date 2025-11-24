#include <string>
#include "Eleve.h"
#include <iostream>
#include <vector>


Eleve::Eleve(const std::string& nom, int note)
    : nom(nom), note(note) {}

std::string Eleve::getNom() const {
    return nom;
}

int Eleve::getNote() const {
    return note;
}


bool CompareNom::operator()(int i, int j) const {
    ++*ptr;
    return tab[i].getNom() < tab[j].getNom();
}

bool CompareNoteDecroissant::operator()(int i, int j) const {
    ++*ptr;
    return tab[i].getNote() > tab[j].getNote();
}

void AfficherDansOrdre(const std::vector<Eleve>& eleves, const std::vector<int>& ordre) {
    for (int index : ordre) {
        std::cout << "Nom: " << eleves[index].getNom() << ", Note: " << eleves[index].getNote() << std::endl;
    }
}