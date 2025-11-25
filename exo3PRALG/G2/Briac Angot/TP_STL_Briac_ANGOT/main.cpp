#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include "eleve.h"

using namespace std;

string genererNom() {
    string nom_de_l_eleve;

    // La première lettre est en majuscule
    // Utiliser 'A' + rand() % 26, cela augmente la valeur ASCII, ce qui va trouver une majuscule aléatoirement (et de même pour 'a' + rand() % 26)

    nom_de_l_eleve += 'A' + rand() % 26;

    // La longueur doit être compris entre 1 et 10
    int longueur_du_nom = 1 + rand() % 10;
    for (int i = 0; i < longueur_du_nom; ++i) {
        nom_de_l_eleve += 'a' + rand() % 26;
    }

    return nom_de_l_eleve;
}

int genererNote() {
    // La note doit être entre 0 et 20
    return rand() % 21;
}


vector<Eleve> genererEleves(int nombre) {
    vector<Eleve> eleves;
    for (int i = 0; i < nombre; ++i) {
        Eleve eleve(genererNom(), genererNote());
        eleves.push_back(eleve);
    }
    return eleves;
}


int main() {
    // On a besoin de ça pour que l'aléatoire le soit vraiment
    srand(time(0));

    // On fixe le nombre d'élèves
    const int NB_ELEVES = 20;
    vector<Eleve> eleves = genererEleves(NB_ELEVES);


    // On affiche la liste des élèves sans tri
    cout << "Liste des élèves sans tri:" << endl;
    afficherVecteur(eleves);
    cout << endl;
    cout << "L'affichage des vecteurs fonctionne." << endl;


    // On les trie désormais par ordre lexicographique
    int compteurNom = 0;
    CompareNom cmprNom(&compteurNom);

    vector<Eleve> elevesTriNom = eleves;
    sort(elevesTriNom.begin(), elevesTriNom.end(), cmprNom);

    cout << "Liste des élèves triés par ordre lexicographique" << endl;
    afficherVecteur(elevesTriNom);
    cout << "Nombre de comparaisons : " << compteurNom << endl << endl;
    cout << "Le trie lexicographique fonctionne" << endl;

    // On trie par note décroissante
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);

    vector<Eleve> elevesTriNote = eleves;
    sort(elevesTriNote.begin(), elevesTriNote.end(), cmpNote);

    cout << "Liste des élèves triés par note décroissante" << endl;
    afficherVecteur(elevesTriNote);
    cout << "Nombre de comparaisons : " << compteurNote << endl;
    cout << "Le trie par ordre décroissant fonctionne." << endl;

    return 0;
}
