#include "eleves.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    //Génération aléatoire d'une classe d'élèves
    std::vector<Eleve> classe;
    for (int i = 0; i < 10; ++i)
        classe.push_back(Eleve(nomAleatoire(), std::rand() % 21));

    std::cout << "Classe initiale :" << std::endl;
    afficherClasse(classe);
    std::cout << std::endl;

    //Tri alphabétique
    int compteur1 = 0;
    std::sort(classe.begin(), classe.end(), CompareNom(&compteur1));
    afficherClasse(classe);
    std::cout << "Nombre de comparaisons sur les noms : " << compteur1 << std::endl;
    std::cout << std::endl;

    //Tri par note décroissante
    int compteur2 = 0;
    std::sort(classe.begin(), classe.end(), CompareNote(&compteur2));
    afficherClasse(classe);
    std::cout << "Nombre de comparaisons sur les notes : " << compteur2 << std::endl;

    return 0;
}
