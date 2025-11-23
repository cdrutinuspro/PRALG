// Imagine++ project
// Project:  Exercice sur la STL
// Author:   Houssam Ehmimed

// #include<Imagine/Graphics.h>
#include "Eleve.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// using namespace Imagine;

int main() {
    std::vector<Eleve> liste_eleves;
    //Longueur de la liste des élèves
    int liste_size = 10;
    for (int i = 0; i < liste_size; i++){
        //Première lettre
        char first_letter = 'A' + (rand() % 26);
        std::string name(1,first_letter);
        //La note
        int grade = rand()%21;
        //Longueur du nom
        int name_size = rand()%10;
        if (name_size>0){
            for (int j = 0; j < name_size; j++){
                name.push_back('a' + rand()%26);
            }
        }
        liste_eleves.push_back(Eleve(name, grade));
    }

    cout << "La liste initiale des eleves" << endl;
    cout << endl;
    afficher(liste_eleves);

    //On compare par rapport aux notes

    int compteur=0;

    CompareNote comparer_note(&compteur);
    std::sort(liste_eleves.begin(), liste_eleves.end(), comparer_note);
    cout << endl;
    cout << "Il y'a eu " << compteur << " comparaisons de notes" << endl;
    cout << endl;
    afficher(liste_eleves);

    //On compare par rapport aux noms

    compteur = 0; //On remets le compteur à 0

    CompareNom comparer_nom(&compteur);
    std::sort(liste_eleves.begin(), liste_eleves.end(), comparer_nom);
    cout << endl;
    cout << "Il y'a eu " << compteur << " comparaisons de noms" << endl;
    cout << endl;
    afficher(liste_eleves);
    return 0;
}


