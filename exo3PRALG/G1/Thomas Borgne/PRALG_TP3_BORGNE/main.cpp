#include "Eleve.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<Eleve> classe;
    const int N = 10;
    for (int i = 0; i < N; ++i)
        classe.push_back(genererEleveAleatoire());

    cout << "Liste initiale :" << endl;
    afficherVector(classe);

    cout << "\n Tri par nom:" << endl;
    int compteurNom = 0;
    CompareNom cmpNom(&compteurNom);
    sort(classe.begin(), classe.end(), cmpNom);
    afficherVector(classe);
    cout << "Nombre de comparaisons : " << compteurNom << endl;

    cout << "\n Tri par note :" << endl;
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    sort(classe.begin(), classe.end(), cmpNote);
    afficherVector(classe);
    cout << "Nombre de comparaisons : " << compteurNote << endl;

    return 0;
}
