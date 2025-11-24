#include "Eleve.h"
using namespace std;
// #include <Imagine/Graphics.h>

// constructeur

Eleve::Eleve(){
    note = 0;
    name = "";
}

Eleve::Eleve(const std::string& nom, int note_eleve){
    name = nom;
    note = note_eleve;
}


// Méthode d'acces

int Eleve::getNote() const{
    return note;
}


std::string Eleve::getName() const{
    return name;
}



// Methode pour attribuer une valeur


void Eleve::setNote(int nouvelleNote){
    note = nouvelleNote;
}

void Eleve::setName(const std::string& nouveauNom){
    name = nouveauNom;
}

// METHODE POUR AFFICHER

void Eleve::afficher() const{
    cout << "Nom: " << name << ", Note: " << note << endl;
}

void afficherEleves(const std::vector<Eleve>& eleves) {

    for (std::vector<Eleve>::const_iterator it = eleves.begin(); it != eleves.end(); ++it) {
        it->afficher(); // C'est le afficher de la classe eleve !!!
    }
}

// faire un élève aléatoire
// j'ai eu des problèmesa avec Imagine sur cette méthode donc je suis retourné sur du rand
Eleve Eleve::genererEleveAleatoire() {
    int note_random = rand() % 21;  // 0-20

    std::string nom = "";
    nom += 'A' + (rand() % 26);  // Lettre majuscule

    int longueur = 1 + (rand() % 10);  // 1-10 caractères supplémentaires
    for (int i = 0; i < longueur; ++i) {
        nom += 'a' + (rand() % 26);  // Lettres minuscules
    }
    return Eleve(nom, note_random);
}


std::vector<Eleve> genererVecteurElevesAleatoires() {
    // Imagine::initRandom();
    std::vector<Eleve> eleves;

    int taille = rand()%20; // Imagine::intRandom(0,20);

    for (int i = 0; i < taille; i++) {
        eleves.push_back(Eleve::genererEleveAleatoire());
    }
    return eleves;
}


CompareNom::CompareNom(int* counter) {
    ptr = counter;
}

CompareNote::CompareNote(int* counter) {
    ptr = counter;
}


bool CompareNom::operator()(const Eleve& a, const Eleve& b) const {
    ++*ptr; // Incrémente le compteur
    return a.getName() < b.getName();
}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const {
    ++*ptr; // Incrémente le compteur
    return a.getNote() > b.getNote();
}









