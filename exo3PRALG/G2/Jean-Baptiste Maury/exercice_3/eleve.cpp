#include "eleve.h"
#include <iostream>
using namespace std;


Eleve::Eleve(int note_mise, std::string nom_mis){
    if (note_mise < 0 || note_mise > 20) {
        throw std::invalid_argument("La note doit être entre 0 et 20");
    }
    note = note_mise;
    if (nom_mis.empty())
        throw std::invalid_argument("Le nom ne peut pas être vide");
    if (!std::isupper(nom_mis[0])) {
        throw std::invalid_argument("Le nom doit commencer par une majuscule");
    }
    nom = nom_mis;

}

void Eleve::display() const {
    std:: pair<int, std::string> p(note, nom);
    std::cout << "Eleve: " << p.second << ", Note: " << p.first << std::endl;
}

std::string Eleve::getNom() {
    return nom ;
}

int Eleve::getNote(){
    return note ; 
}


CompareNom::CompareNom(int* compteur) : ptr(compteur) {}

bool CompareNom::operator()(Eleve eleve1, Eleve eleve2) {
    (*ptr)++;
    return eleve1.getNom() > eleve2.getNom();
}

CompareNote::CompareNote(int* compteur) : ptr(compteur) {}

bool CompareNote::operator()(Eleve eleve1, Eleve eleve2) {
    (*ptr)++;
    return eleve1.getNote() > eleve2.getNote();
}

