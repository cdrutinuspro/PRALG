#include "eleve.h"

Eleve::Eleve(const std::string& n, int nt) {
    nom = n;
    note = nt;}

std::string Eleve::getNom() const {return nom;}

int Eleve::getNote() const {return note;}

void Eleve::setNom(const std::string& newNom) {this->nom = newNom;}

void Eleve::setNote(int newNote) {
    if (newNote >= 0 && newNote <= 20) {
        this->note = newNote;}
    else {
        this->note = 20;
    }
}

std::ostream& operator<<(std::ostream& os, const Eleve& e) {
    os << "Eleve [Nom: " << e.getNom() << ", Note: " << e.getNote() << "]";
    return os;
}

bool compareNom(const Eleve& a, const Eleve& b) {
    return a.getNom() < b.getNom();
}

bool compareNote(const Eleve& a, const Eleve& b) {
    return a.getNote() < b.getNote();
}


void afficher(const std::string& titre, const std::vector<Eleve>& eleves) {
    std::cout << "!" << titre << "!" << std::endl;
    for (std::vector<Eleve>::const_iterator it = eleves.begin(); it != eleves.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
}


// A la fin... j'ai choisi de ne pas utiliser setNom ni setNote...
void remplirClasse(std::vector<Eleve>& classe) {
    int nombreEleves = 1 + (rand() % 25);
    for (int i = 0; i < nombreEleves; ++i) {
        int noteAleatoire = rand() % 21;
        std::string nomAleatoire;
        nomAleatoire += 'A' + (rand() % 26);
        int lenMin = 1 + (rand() % 10);
        for (int j = 0; j < lenMin; ++j) {
            nomAleatoire += 'a' + (rand() % 26);
        }
        classe.push_back(Eleve(nomAleatoire, noteAleatoire));
    }
}
