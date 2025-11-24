#include "eleve.h"

Eleve :: Eleve(string name, int grade){
    nom = name;
    note = grade;
}

Eleve :: Eleve(const Eleve& E){
    nom = E.nom;
    note = E.note;
}


string Eleve :: getNom() const{
    return nom;
}

int Eleve :: getNote() const{
    return note;
}


Eleve randomEleve(){
    int note = arc4random() % 21;
    //Génération d'un nom aléatoire avec la premiere lettre en majuscule
    int longueur = arc4random() % 11;
    string nom;

    // Première lettre majuscule
    nom += static_cast<char>('A' + arc4random() % 26);

    // Lettres suivantes minuscules
    for (int i = 0; i < longueur; ++i) {
        nom += static_cast<char>('a' + arc4random() % 26);
    }
    return Eleve(nom, note);
}

