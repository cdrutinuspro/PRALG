#include <iostream>
#include <vector>
#include <cstdlib>
#include "eleve.h"
#include <ctime>
#include <algorithm>

using namespace std;

string nomAleatoire() {
    int longueur = rand() % 10 + 1; // entre 1 et 10 lettres minuscules après la majuscule
    string nom;
    nom += 'A' + rand() % 26; // la première lettre est majuscule
    for (int i = 0; i < longueur; ++i) {
        nom += 'a' + rand() % 26; // choix au hasard des lettres minuscules
    }
    return nom;
}

int noteAleatoire() {
    return rand() % 21;
}


 void afficherVector(const vector<Eleve>& v) {
    // affichage avec itérateurs (comme demandé)
    for (auto it = v.begin(); it != v.end(); ++it) it->afficher();
 }


int main()
{
    srand(time(nullptr)); // pour que rand() donne des valeurs différentes à chaque exécution (astuce trouvée sur cpluplus.com)

    vector<Eleve> eleves;

    int n = 10; // nombre d’élèves à créer
    for (int i = 0; i < n; ++i) {
        string nom = nomAleatoire();
        int note = noteAleatoire();
        eleves.push_back(Eleve(nom, note)); // création et ajout dans le vecteur
    }




    // essai

    cout << "Donnees initiales\n";
    afficherVector(eleves);

    // Tri 1 : alphabétique
    int compteurNom = 0;
    CompareNom cmpNom(&compteurNom);
    sort(eleves.begin(), eleves.end(), cmpNom);

    cout << "\n Tri alphabétique\n";
    afficherVector(eleves);
    cout << "Comparaisons (nom) : " << compteurNom << "\n";

    // Tri 2 : par note décroissante
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    sort(eleves.begin(), eleves.end(), cmpNote);

    cout << "\nTri par note (decroissant) \n";
    afficherVector(eleves);
    cout << "Comparaisons (note) : " << compteurNote << "\n";


    return 0;
}
