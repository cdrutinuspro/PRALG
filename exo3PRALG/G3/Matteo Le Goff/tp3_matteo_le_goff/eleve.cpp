#include "eleve.h"
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

Eleve::Eleve(string nom, int note): nom(nom), note(note) {}

string Eleve::getNom() const{
    return nom;
}

int Eleve::getNote() const{
    return note;
}

void afficherClasse(const vector<Eleve>& classe){
    for(int k = 0; k<classe.size(); ++k){
        cout << classe.at(k).getNom() << " || " << classe.at(k).getNote() << endl;
    }
}
