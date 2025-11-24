#include <iostream>
#include <algorithm>
#include "eleve.h"

using namespace std;
// using namespace Imagine;

int main()
{
//     initRandom();

    int compteur_1 = 0;
    CompareNom cpm_nom = CompareNom(&compteur_1);

    std::vector<Eleve> liste_eleves = genererEleves(20);

    sort(liste_eleves.begin(),liste_eleves.end(),cpm_nom); // Tri selon l'ordre alphabetique
    cout << "\n Affichage tri par ordre alphabetique \n" << endl;
    afficherEleves(liste_eleves);
    cout << "\n Au cours de ce tri : "<< compteur_1
         << " comparaisons ont ete effectuees"<< endl;

    int compteur_2 = 0;
    CompareNote cpm_note = CompareNote(&compteur_2);
    sort(liste_eleves.begin(),liste_eleves.end(),cpm_note); // Tri selon les notes decroissantes
    cout << "\n Affichage tri par notes decroissantes \n" << endl;
    afficherEleves(liste_eleves);
    cout << "\n Au cours de ce tri : "<< compteur_2
         << " comparaisons ont ete effectuees"<< endl;

    return 0;
}
