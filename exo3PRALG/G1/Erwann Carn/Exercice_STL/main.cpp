#include "eleve.h"
#include "comparateur.h"
#include <iostream>
#include <algorithm>
#include "affichage.h"
#include "eleve.h"
#include "comparateur.h"
using namespace std;

int main(){
    vector<Eleve> v;
    generate(v, 100);

    afficher(v, "Liste initiale");

    auto vNom = v;
    int compteur = 0;
    CompareNom cmpNom;
    cmpNom.ptr = &compteur;
    std::sort(vNom.begin(), vNom.end(), cmpNom);
    afficher(vNom, "Tri par nom (alphabétique)");
        std::cout << "Comparaisons (nom): " << compteur << "\n";

    auto vNote = v;
    compteur = 0;
    CompareNote cmpNote{ &compteur; };
    std::sort(vNote.begin(), vNote.end(), cmpNote);
    afficher(vNote, "Tri par note (décroissant)");
        std::cout << "Comparaisons (note): " << compteur << "\n";

    return 0;
}
