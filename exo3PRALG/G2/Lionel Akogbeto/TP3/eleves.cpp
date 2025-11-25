#include "eleves.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

//Classe Eleve
Eleve::Eleve(std::string n, int no) : nom(n), note(no) {}

void Eleve::afficher() const {
    std::cout << nom << ", NOTE:" << note << std::endl;
}

//Foncteurs
CompareNom::CompareNom(int* p) : ptr(p) {}

bool CompareNom::operator()(const Eleve& a, const Eleve& b) const {
    ++*ptr;
    return a.nom < b.nom;
}

CompareNote::CompareNote(int* p) : ptr(p) {}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const {
    ++*ptr;
    return a.note > b.note; // tri décroissant
}

//Fonctions utilitaires
std::string nomAleatoire() {
    int taille = 1 + std::rand() % 10; //un nombre au hasard entre 1 et 10
    std::string nom;
    nom += char('A' + std::rand() % 26);
    for (int i = 0; i < taille; ++i)
        nom += char('a' + std::rand() % 26);
    return nom;
}

void afficherClasse(const std::vector<Eleve>& vec) {
    for (std::vector<Eleve>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        it->afficher();
}
