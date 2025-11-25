// Imagine++ project
// Project:  TP3
// Student(s): Clara Lima Goldenberg

#include "eleves.h"
#include <vector>
#include <iostream>
using namespace std;

void afficher_vecteur(vector<Eleve> eleves){

 //On crée un itérateur
    vector<Eleve>::iterator it;

    for (it = eleves.begin(); it != eleves.end(); ++it){
        cout<< it->get_nom() << " : " << it->get_note() <<endl;
    }
}

int main() {
    int nombre_eleves = rand()%30;
    vector<Eleve> eleves_tri_note(nombre_eleves);
    vector<Eleve> eleves_tri_nom(nombre_eleves);

    int compteur = 0;

    CompareNote cmpno;
    cmpno.set_compteur(compteur);
    sort(eleves_tri_note.begin(), eleves_tri_note.end(), cmpno);
    afficher_vecteur(eleves_tri_note);
    cout << "Nombre de comparaisons, tri par note :" << compteur <<endl;

    CompareNom cmpn;
    compteur = 0;
    cmpn.set_compteur(compteur);
    sort(eleves_tri_nom.begin(), eleves_tri_nom.end(), cmpn);
    afficher_vecteur(eleves_tri_nom);
    cout << "Nombre de comparaisons, tri par nom :" << compteur <<endl;

    return 0;
}


