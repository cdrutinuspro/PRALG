#include "Eleve.h"
#include <algorithm>

// constructeur
Eleve::Eleve(std::string Nom, int Note){
    note=Note;
    nom=Nom;
};

// getteur nom, note
std::string Eleve::getNom() const {
    return nom ;
};

int Eleve::getNote() const {
    return note ;
};

// afficher nom et note
void Eleve::affichageNom() const {
    std::cout<< nom << " " ;
};

void Eleve::affichageNote() const {
    std::cout<< nom << " : " << note << " " ;
};


// // // Afficher les vecteurs
void affichageNoms(std::vector<Eleve>& eleves) {
    // inverser le vector
    std::reverse(eleves.begin(), eleves.end());
    // afficher le vector
    for (const Eleve& eleve : eleves){
        eleve.affichageNom();
    }
};
void affichageNotes(std::vector<Eleve>& eleves){
    // inverser le vector
    std::reverse(eleves.begin(), eleves.end());
    // afficher le vector
    for (const Eleve& eleve : eleves){
        eleve.affichageNote();
    }
} ;
