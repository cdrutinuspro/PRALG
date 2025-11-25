#include <iostream>
#include <string> 
#include <vector>
#include "eleves.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void afficher_vecteur(const vector<Eleve>& vect){
    for (auto it = vect.begin(); it != vect.end(); ++it){
        it->afficher();
    }
}

vector<Eleve> remplissage(int taille) {
    vector<Eleve> vecteur;
    for (int i = 0; i < taille; i++) {
        int note_random = rand() % 21;
        int taille_nom = rand() % 10 + 1;
        char maj = 'a' + rand() % 26;
        maj = toupper(maj);
        string nom(1, maj);
        for (int j = 1; j < taille_nom; j++) {
            char c = 'a' + rand() % 26;
            nom += c;
        }
        Eleve e(nom, note_random);
        vecteur.push_back(e);
    }
    return vecteur;
}

int main(){
   int compteur_notes = 0;
   int compteur_noms = 0; 
   CompareNotes cmp_notes(&compteur_notes);
   CompareNoms cmp_noms(&compteur_noms);
   vector<Eleve> eleves = remplissage(10);
   cout<<"Tri par noms:\n";
   sort(eleves.begin(), eleves.end(), cmp_noms);
   afficher_vecteur(eleves);
   cout << "\n";
   sort(eleves.begin(), eleves.end(), cmp_notes);
   cout<<"Tri par notes:\n";
   afficher_vecteur(eleves);
   cout<<"\n";
   cout<<compteur_notes;
   cout<<"\n";
   cout<<compteur_noms;
}