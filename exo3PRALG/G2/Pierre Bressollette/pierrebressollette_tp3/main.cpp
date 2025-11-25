#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Eleve.h"
using namespace std;

// Fonction pour générer un nom aléatoire
string genererNom() {
    string nom;
    nom += char('A' + rand() % 26);  // Majuscule
    int longueur = 1 + rand() % 10;   // 1 à 10 lettres minuscules
    for (int i = 0; i < longueur; i++) {
        nom += char('a' + rand() % 26);
    }
    return nom;
}

// Fonction pour afficher le vecteur
void afficher(const vector<Eleve>& classe) {
    for (vector<Eleve>::const_iterator it = classe.begin(); 
         it != classe.end(); ++it) {
        cout << it->getNom() << " (" << it->getNote() << ") ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Initialisation aléatoire avec l'heure
    
    // Remplir le vecteur avec des élèves aléatoires
    vector<Eleve> classe;
    int nbEleves = 10;  // Nombre d'élèves (changeable)
    
    for (int i = 0; i < nbEleves; i++) {
        string nom = genererNom();
        int note = rand() % 21;  // Note entre 0 et 20
        classe.push_back(Eleve(nom, note));
    }
    
    cout << " Liste initiale " << endl;
    afficher(classe);
    cout << endl;
    
    // Tri alphabétique
    int compteurNom = 0;
    CompareNom cmpNom(&compteurNom);
    sort(classe.begin(), classe.end(), cmpNom);
    
    cout << " Tri alphabetique " << endl;
    afficher(classe);
    cout << "Nombre de comparaisons : " << compteurNom << endl << endl;
    
    // Tri par note décroissante
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    sort(classe.begin(), classe.end(), cmpNote);
    
    cout << " Tri par note decroissante " << endl;
    afficher(classe);
    cout << "Nombre de comparaisons : " << compteurNote << endl;
    
    return 0;
}