#include "Comparateur.h"
#include <iostream>
#include <algorithm>


int main() {
    std::vector<Eleve> classe = random_class(10);

    std::cout << "Liste des eleves generes :" << std::endl;
    afficher_classe(classe);

    int compteur = 0;
    CompareNom cmpNom(&compteur);
    std::sort(classe.begin(), classe.end(), cmpNom);
    std::cout << "\nClasse triee par nom :" << std::endl;
    afficher_classe(classe);
    std::cout << "Nombre de comparaisons : " << compteur << std::endl;

    compteur = 0;
    CompareNote cmpNote(&compteur);
    std::sort(classe.begin(), classe.end(), cmpNote);
    std::cout << "\nClasse triee par note :" << std::endl;
    afficher_classe(classe);
    std::cout << "Nombre de comparaisons : " << compteur << std::endl;

    return 0;

}
