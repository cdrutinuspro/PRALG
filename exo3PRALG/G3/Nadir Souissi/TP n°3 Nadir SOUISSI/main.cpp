#include <iostream>
#include <algorithm>
#include "Eleve.h"
#include <ctime> 
using namespace std;
#include <vector>
#include <cstdlib>


int main() {
    srand(time(0));
    vector<Eleve> classe = listofStudents(10);
    int compteur = 0;

    // Tri par nom
    CompareName name(&compteur);
    sort(classe.begin(), classe.end(), name);
    cout << "\n--- Tri par nom --- (" << compteur << " comparaisons)\n";
    affichage(classe);

    // Tri par note décroissante
    compteur = 0; // on réinitialise
    CompareGrade Grade(&compteur);
    sort(classe.begin(), classe.end(), Grade);
    cout << "\n--- Tri par note décroissante --- (" << compteur << " comparaisons)\n";
    affichage(classe);

    return 0;
}
