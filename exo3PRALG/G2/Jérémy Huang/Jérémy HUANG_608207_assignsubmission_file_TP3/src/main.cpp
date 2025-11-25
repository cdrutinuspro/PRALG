#include <vector>
#include "Eleve.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

int main(){
    // Gérération 20 élèves 
    srand(time(0));
    std::vector<Eleve> liste_eleve;
    for (int i=0; i<20; i++){

        // Génération du nom
        int length = 1 + rand()%10;
        std::string nom = "";
        nom += char('A' + rand()%26);
        for (int j=0; j<length; j++){
            nom += char('a' + rand()%26);
        }

        // Génération de la note
        int note = rand()%21;

        // Génération de l'élève aléatoire
        Eleve e(nom, note);
        liste_eleve.push_back(e);
    }
    std::cout << "Liste des élèves : " << std::endl;
    for (const Eleve& e : liste_eleve){
        std::cout << e.get_nom() << " : " << e.get_note() << std::endl;
    }

    std::cout << std::endl;
    CompareNom c_nom = sort_by_nom(liste_eleve);
    std::cout << "Nombre de comparaisons (nom) : " << c_nom.get_ptr() << std::endl;

    std::cout << std::endl;
    CompareNote d_note = sort_by_note(liste_eleve);
    std::cout << "Nombre de comparaisons (note) : " << d_note.get_ptr() << std::endl;

    return 0;
};