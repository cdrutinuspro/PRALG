// Imagine++ project
// Student(s): Emma Leblanc

#include "eleve.h"
#include <ctime>
#include <iostream>

// #include <Imagine/Graphics.h>
using namespace std;

int main() {
    // On créé un vecteur de 10 élèves
    vector<Eleve> eleves;
    for(int i=0;i<10;i++){
        Eleve eleve;
        eleve.random_init();
        eleves.push_back(eleve);
    }
    //tri alphabétique des élèves
    int compteur = 0;
    CompareNom compare_nom;
    compare_nom.set_ptr(compteur);
    cout << "Tri alphabétique:"<<endl;
    sort(eleves.begin(),eleves.end(),compare_nom);
    for(int i=0;i<eleves.size();i++){
        eleves[i].show();
    };
    cout<<"nombre de comparaisons: "<< compteur<<endl;
    compteur = 0;
    //tri numérique des élèves
    CompareNote compare_note;
    compare_note.set_ptr(compteur);
    cout << "Tri numérique" << endl;
    sort(eleves.begin(),eleves.end(),compare_note);
    for(int i=0;i<eleves.size();i++){
        eleves[i].show();
    };
    cout<<"nombre de comparaisons: "<< compteur<<endl;
    return 0;
}
