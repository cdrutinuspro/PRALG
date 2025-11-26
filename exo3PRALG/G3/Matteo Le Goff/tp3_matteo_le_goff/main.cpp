#include <utility>
#include <algorithm>
#include "eleve.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{   vector<Eleve> classe = {};
    for(int i = 0; i<20; ++i){
        int note = rand() % 21; // rand() renvoie un entier, donc ici on prend un entier aléatoire en 0 et 20
        string nom;
        nom += 'A' + (rand() % 26);  // les lettres sont codées en ASCII de manière croissante, donc ici on parcourt l'alphabet majuscule
        for (int j = 0; j < 9; ++j){
            nom += 'a' + rand() % 26; // les lettres sont codées en ASCII de manière croissante, donc ici on parcourt l'alphabet miniscule
        }
        classe.push_back(Eleve(nom, note));
    }
    int compteur = 0;
    CompareNom cmpNom;
    cmpNom.ptr = &compteur; // ptr pointe vers un alias du compteur, en modifiant l'un, sachant qu'ils sont maintenant adressés vers le même espace mémoire, on modifie les 2
    sort(classe.begin(), classe.end(), cmpNom); // on traite bien avec la fonction CompareNom déjà initialisée, sinon notre compteur ne bougera pas (erreur initialement faite)
    afficherClasse(classe);
    cout << "\n ***\n" << endl;
    cout << "Nombre de comparaisons pour le tri par ordre alphabétique: " << compteur << endl;
    compteur = 0;
    CompareNote cmpNote;
    cmpNote.ptr= &compteur;
    cout << "\n ***\n" << endl;
    sort(classe.begin(), classe.end(), cmpNote);
    afficherClasse(classe);
    cout << "\n ***\n" << endl;
    cout << "Nombre de comparaisons pour le tri par note: " << compteur << endl;
}
