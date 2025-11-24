#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// #include <Imagine/Graphics.h>
#include "Eleve.h"
using namespace std;

int main() {

    cout << "Generation du vecteur d\'eleves aleatoires" << endl;
    vector<Eleve> eleves = genererVecteurElevesAleatoires();
    cout << "Vecteur initial:" << endl;
    afficherEleves(eleves);
    cout << "" << endl;

    // Définir le compteur pour le tri par nom
    int compteurNom = 0;

    // Tri alphabétique
    cout << "Tri par nom (ordre alphabetique)";
    cout << "" << endl;
    CompareNom cmpNom(&compteurNom);
    sort(eleves.begin(), eleves.end(), cmpNom);
    afficherEleves(eleves);
    cout << "" << endl;
    cout << "Nombre de comparaisons effectuees pour le tri par nom: " << compteurNom << endl;
    cout << "" << endl;

    // Définir le compteur pour le tri par note
    int compteurNote = 0;

    // Tri par note décroissante
    cout << "Tri par note (ordre decroissant)";
    cout << "" << endl;
    CompareNote cmpNote(&compteurNote);
    sort(eleves.begin(), eleves.end(), cmpNote);
    afficherEleves(eleves);
    cout << "" << endl;
    cout << "Nombre de comparaisons effectuees pour le tri par note: " << compteurNote << endl;
    cout << "" << endl;

    return 0;
}

