#include "eleve.h"
#include <iostream>
// #include <QCoreApplication>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::string genererNom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_longueur(1, 10);
    std::uniform_int_distribution<> dist_lettre('a', 'z');

    int longueur = dist_longueur(gen);
    std::string nom;

    nom += static_cast<char>('A' + dist_lettre(gen) - 'a');

    for (int i = 1; i < longueur; ++i) {
        nom += static_cast<char>(dist_lettre(gen));
    }

    return nom;
}

void afficherEleves(const std::vector<Eleve>& eleves, const std::string& titre) {
    std::cout << "\n" << titre << ":\n";

    for (const auto& eleve : eleves) {
        eleve.afficher();
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_note(0, 20);

    const int NB_ELEVES = 10;
    std::vector<Eleve> eleves;

    std::cout << "Génération de " << NB_ELEVES << " élèves...\n";
    for (int i = 0; i < NB_ELEVES; ++i) {
        std::string nom = genererNom();
        int note = dist_note(gen);
        eleves.push_back(Eleve(nom, note));
    }

    afficherEleves(eleves, "Liste initiale des élèves");

    int compteur_nom = 0;
    CompareNom cmp_nom(&compteur_nom);

    std::sort(eleves.begin(), eleves.end(), cmp_nom);
    afficherEleves(eleves, "Élèves triés par nom");
    std::cout << "Nombre de comparaisons effectuées : " << compteur_nom << "\n";

    // Tri par note (ordre décroissant)
    int compteur_note = 0;
    CompareNote cmp_note(&compteur_note);

    std::sort(eleves.begin(), eleves.end(), cmp_note);
    afficherEleves(eleves, "Élèves triés par note (décroissant)");
    std::cout << "Nombre de comparaisons effectuées : " << compteur_note << "\n";

    return 0;
}
