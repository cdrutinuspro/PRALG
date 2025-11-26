#include "Eleve.h"

int Eleve::getNote() const{ return note; }

void Eleve::setNote(int d) {note = d; }

string Eleve::getNom() const{ return nom; }

void Eleve::setNom(string d) {nom = d; }

Eleve::~Eleve(){}

void Eleve::displaycout(string indent) const{
    cout << nom << indent << note << endl;
}



bool CompareNom::operator ()(int i, int j) const{
    string nom_i = classe[i].getNom();
    string nom_j = classe[j].getNom();
    int len_min = min(nom_i.length(), nom_j.length());
    if (ptr) ++*ptr;
    for (int k = 0; k < len_min; k++) {
        if (nom_i[k] < nom_j[k]) return true;
        if (nom_i[k] > nom_j[k]) return false;
    }
    return nom_i.length() < nom_j.length(); // si tous les caractères égaux
}



bool CompareNote::operator ()(int i, int j) const{
    int note_i = classe[i].getNote();
    int note_j = classe[j].getNote();
    if (ptr) ++*ptr;
    return note_i > note_j;
}



bool CompareNoteNom::operator ()(int i, int j) const{
    if (ptr) ++*ptr;
    if (classe[i].getNote() != classe[j].getNote())
        return classe[i].getNote() > classe[j].getNote(); // note décroissante
    return classe[i].getNom() < classe[j].getNom();       // nom croissant si notes égales
}
