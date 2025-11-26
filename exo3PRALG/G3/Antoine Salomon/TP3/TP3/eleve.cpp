#include "Eleve.h"
#include <iostream>
using namespace std ;

Eleve::Eleve() {
    nom = "";
    note = 0;
}

Eleve::Eleve(string n, int no) {
    nom = n;
    note = no;
}

string Eleve::getNom() const {
    return nom;
}

int Eleve::getNote() const {
    return note;
}

void Eleve::setNom(string n) {
    nom = n;
}

void Eleve::setNote(int n) {
    note = n;
}
