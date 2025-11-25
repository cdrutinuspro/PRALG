#include "eleve.h"
#include <algorithm>
#include <vector>


// Constructeur
Eleve::Eleve(string n, int no) : nom(n), note(no) {}


// renvoie le nom de l'élève
string Eleve::nomEleve() const {
    return nom;
}

// renvoie la note de l'élève
int Eleve::noteEleve() const {
    return note;
}

// modifie le nom de l'élève
void Eleve::modifierNom(string n) {
    nom = n;
}

// modifie la note de l'élève
void Eleve::modifierNote(int n) {
    note = n;
}

// fonction d'affichage
void Eleve::afficher() const {
    cout << "Nom: " << nom << "; note: " << note << "/20" << endl;
}

// Fonction qui compare les noms, si l'élève 1 a un nom inférieur à celui ce l'élève 2
bool CompareNom::operator()(const Eleve& e1, const Eleve& e2) {
    ++(*ptr);
    return e1.nomEleve() < e2.nomEleve();
}

// Ici vérifie si la note de l'élève numéro 1 est supérieur à celle de l'élève 2
bool CompareNote::operator()(const Eleve& e1, const Eleve& e2) {
    ++(*ptr);
    return e1.noteEleve() > e2.noteEleve();
}

// Ici on procède avec un itérateur
void afficherVecteur(const vector<Eleve>& eleves) {
    auto it = eleves.begin();
    while (it != eleves.end()) {
        it->afficher();
        ++it;
    }
}
