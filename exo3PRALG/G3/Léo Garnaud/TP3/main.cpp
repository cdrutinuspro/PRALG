#include <iostream>
#include "eleves.h"
// #include <Imagine/Graphics.h>
// using namespace Imagine;

using namespace std;

const int nb_eleves_max = 30;
const int nb_lettre_max = 10;

void affiche_eleves(vector<Eleve> eleves){
    for (int i=0; i<int(eleves.size()); i++)
        eleves.at(i).affiche();
}

int main(){
    // initRandom();
    vector<Eleve> eleves(0);
    int nb_eleves = 1 + rand()%nb_eleves_max; //(1, nb_eleves_max);
    int compteur = 0;
    for (int i=0; i<nb_eleves; i++){
        int note =  rand()%21; //intRandom(0, 20);
        string nom = "";
        char lettre = 'A' + rand()%26;
        nom = nom + lettre;
        for (int j=0; j<1 + rand()%nb_lettre_max; j++){
            char lettre = 'a' + rand()%26;
            nom = nom + lettre;
        }
        Eleve eleve(nom, note);
        eleves.resize(eleves.size()+1);
        eleves[eleves.size()-1] = eleve;
    }
    CompareNote cmp_note;
    cmp_note.ptr = &compteur;
    sort(eleves.begin(), eleves.end(),cmp_note);
    affiche_eleves(eleves);
    cout << "nombre de comparaisons pour le tri en fonction des notes: " << *cmp_note.ptr << endl;
    int compteur_2 = 0;
    CompareNom cmp_nom;
    cmp_nom.ptr = &compteur_2;
    sort(eleves.begin(), eleves.end(),cmp_nom);
    affiche_eleves(eleves);
    cout << "nombre de comparaisons pour le tri en fonction des noms: " << *cmp_nom.ptr << endl;

    return 0;
}
