#include "Eleve.h"
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

//Display function
void afficher(const vector<Eleve>& eleves) {
    for (auto it = eleves.begin(); it != eleves.end(); ++it)
        cout << it->name() << " : " << it->grade() << endl;
    cout << endl;
}


int main(){
    vector<Eleve> eleves;
    int n = 10;
    //We fix the seed in order to get the same result
    mt19937 gen(42);

    //We use uniform distributions to select characters and integers randomly
    uniform_int_distribution<int> note_dist(0, 20);
    uniform_int_distribution<int> nom_dist(1, 10);
    uniform_int_distribution<int> maj_dist('A', 'Z');
    uniform_int_distribution<int> min_dist('a', 'z');

    //for loop enabling the creation of eleves' objets randomly
    for (int i = 0; i < n; ++i) {
        string nom;
        nom += static_cast<char>(maj_dist(gen));
        int len = nom_dist(gen);
        for (int j = 0; j < len; ++j)
            nom += static_cast<char>(min_dist(gen));
        int note = note_dist(gen);
        eleves.emplace_back(nom, note);
    }

    //Displaying the list of students before sorting
    cout << " Liste des eleves avant le tri" << endl;
    afficher(eleves);
    cout << endl;

    //Initializing the counters for number of iterations for alphabetical or numerical sorting processes
    int compteur_nom = 0;
    int compteur_note = 0;

    //Assigning reference value to the pointer defined in CompareNom class
    CompareNom comp_nom;
    comp_nom.ptr = &compteur_nom;

    //Creating seperate vector for alphabetical ordering
    vector<Eleve> tri_alphab = eleves;
    sort(tri_alphab.begin(), tri_alphab.end(), comp_nom);
    cout << "Liste des eleves par tri alphabetique" <<endl;
    afficher(tri_alphab);

    //Displaying number of iterations for the ordering process
    cout << "Nombre de comparaisons effectuees: " << compteur_nom << endl;
    cout << endl;

    //Assigning reference value to the pointer defined in CompareNote class
    CompareNote comp_note;
    comp_note.ptr = &compteur_note;

    //Creating separate vector for numerical ordering
    vector<Eleve> tri_note = eleves;
    sort(tri_note.begin(), tri_note.end(), comp_note);
    cout << "Liste des eleves par tri des notes decroissantes" << endl;
    afficher(tri_note);

    //Displaying number of iterations for the ordering process
    cout << "Nombre de comparaisons effectuees: " << compteur_note << endl;

    return 0;
}
