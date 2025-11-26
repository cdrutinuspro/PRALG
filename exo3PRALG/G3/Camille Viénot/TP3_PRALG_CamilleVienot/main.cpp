#include <algorithm>
#include <iostream>
#include <vector>
#include "Eleve.h"

using namespace std;

int main()
{
    int compteur = 0;
    // initialiser le compteur des foncteurs
    CompareName cmpName(compteur) ;
    CompareNote cmpNote(compteur) ;

    // creation de la liste d eleves
    std::vector<Eleve> listeEleve = {Eleve("Gael", 10),
                                     Eleve("Leonard", 12),
                                     Eleve("Loan",14),
                                     Eleve("Romain", 16),
                                     Eleve("Juliette",18)};

    // Trie + affiche selon l'ordre lexicographique les noms
    try{
        std::sort(listeEleve.begin(), listeEleve.end(), cmpName);
        affichageNoms(listeEleve) ;
        std::cout<< endl ;
        std::cout<<cmpName.getCompteur() << endl ;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Erreur lors du tri par nom : " << e.what() << std::endl;
        return 1;
    }

    // Trie + affiche selon les notes
    try{
        std::sort(listeEleve.begin(), listeEleve.end(), cmpNote);
        affichageNotes(listeEleve);
        std::cout<< endl ;
        std::cout<<cmpNote.getCompteur() << endl ;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Erreur lors du tri par note : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
