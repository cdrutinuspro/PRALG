#include "Eleves.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

void afficher(std::vector<Eleve> v) {
    std::vector<Eleve>::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
        std::cout << it->nom << " : " << it->note << std::endl;
    }
}

int main() {
    srand(time(0));

    std::vector<Eleve> eleves;

    // Génération aléatoire
    int i;
    for(i = 0; i < 10; i++) {
        std::string nom;
        nom += (char)('A' + rand() % 26);
        int longueur = 1 + rand() % 10;
        int j;
        for(j = 0; j < longueur; j++) {
            nom += (char)('a' + rand() % 26);
        }
        int note = rand() % 21;
        eleves.push_back(Eleve(nom, note));
    }

    // Tri alphabétique
    int compteur = 0;
    CompareNom cmpNom(&compteur);
    std::sort(eleves.begin(), eleves.end(), cmpNom);

    std::cout << "=== Tri alphabétique ===" << std::endl;
    afficher(eleves);
    std::cout << "Nombre de comparaisons : " << compteur << std::endl << std::endl;

    // Tri par note décroissante
    compteur = 0;
    CompareNote cmpNote(&compteur);
    std::sort(eleves.begin(), eleves.end(), cmpNote);

    std::cout << "=== Tri par note décroissante ===" << std::endl;
    afficher(eleves);
    std::cout << "Nombre de comparaisons : " << compteur << std::endl;

    return 0;
}
