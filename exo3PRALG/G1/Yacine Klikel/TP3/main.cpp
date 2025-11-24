# include <iostream>
#include <vector>
#include "Eleve.h"
#include <cstdlib>
#include <algorithm>

int main() {
    std::vector<Eleve> eleves;
    char Alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char alphabetmin[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0; i < 20; ++i) {
        int note = rand() % 21;
        std::string nom;
        nom += Alphabet[rand() % 26];
        int longueur = rand() % 10;
        for (int j = 0; j <= longueur; ++j) {
            nom += alphabetmin[rand() % 26];
        }
        eleves.emplace_back(nom, note);
    }

    std::vector<int> ordreNom(eleves.size());
    std::vector<int> ordreNote(eleves.size());
    for (size_t i = 0; i < eleves.size(); ++i) {
        ordreNom[i] = i;
        ordreNote[i] = i;
    }
    int compteurNom = 0;
    int compteurNote = 0;

    std::sort(ordreNom.begin(), ordreNom.end(), CompareNom(eleves, &compteurNom));
    std::sort(ordreNote.begin(), ordreNote.end(), CompareNoteDecroissant(eleves, &compteurNote));

    std::cout << "Nombre de comparaisons pour le tri par nom: " << compteurNom << std::endl;
    std::cout << "Nombre de comparaisons pour le tri par note: " << compteurNote << std::endl;
    std::cout << std::endl;

    std::cout << "Eleves triés par nom :" << std::endl;
    AfficherDansOrdre(eleves, ordreNom);
    std::cout << std::endl;
    
    std::cout << "Eleves triés par note (décroissantes):" << std::endl;
    AfficherDansOrdre(eleves, ordreNote);

    return 0;
}