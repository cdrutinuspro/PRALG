#include "eleve.h"
#include <iostream>
using namespace std;

// Constructeur par défaut
Eleve::Eleve() : nom("Inconnu"), moyenne(0.0) {
}

// Constructeur avec paramètres
Eleve::Eleve(string n, float m) : nom(n), moyenne(m) {
}

// Constructeur par copie
Eleve::Eleve(const Eleve& other) : nom(other.nom), moyenne(other.moyenne) {
}

// Destructeur
Eleve::~Eleve() {
}

// Méthodes
string Eleve::getNom() const { return nom; }
float Eleve::getMoyenne() const { return moyenne; }
void Eleve::setMoyenne(float m) { moyenne = m; }
