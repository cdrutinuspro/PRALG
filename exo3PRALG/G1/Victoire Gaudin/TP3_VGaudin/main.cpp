#include <iostream>

using namespace std;
#include "eleve.h"

int main()
{
    srand(time(0));
    vector<Eleve> classe;
    Eleve::remplirvecteur(classe, 10);

    int compteurnom = 0;
    int compteurnote = 0;
    Eleve::triervecteurnote(classe, &compteurnote);
    Eleve::affichervecteur(classe);
    cout << "Nombre de comparaisons pour le tri par note " << compteurnote << endl;

    Eleve::triervecteurnom(classe, &compteurnom);
    Eleve::affichervecteur(classe);
    cout << "Nombre de comparaisons pour le tri par nom " << compteurnom << endl;

    return 0;
}
