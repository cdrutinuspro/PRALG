#include "eleve.h"

int main() {
    srand(time(0));
    std::vector<Eleve> classe;

    remplirClasse(classe);
    std::cout << "Une classe de " << classe.size() << " eleves a ete generee aleatoirement." << std::endl;

    afficher("Liste initiale non triee", classe);

    //Tri par nom
    int compteurComparaisons = 0;
    std::cout << ">>>Resultat du tri par nom:" << std::endl;
    std::sort(classe.begin(), classe.end(), CompareNom(&compteurComparaisons));
    afficher("Liste triee par nom (alphabetique)", classe);
    std::cout << ">>> Le nombre de comparaisons pour le tri par nom est de " << compteurComparaisons <<"." << std::endl << std::endl;

    //Tri par note décroissante
    compteurComparaisons = 0;
    std::cout << ">>> Resulat du tri par note:" << std::endl;
    std::sort(classe.begin(), classe.end(), CompareNote(&compteurComparaisons));
    afficher("Liste triee par note (decroissante)", classe);
    std::cout << ">>> Le nombre de comparaisons pour le tri par note est de " << compteurComparaisons <<"." << std::endl;

    return 0;
}
