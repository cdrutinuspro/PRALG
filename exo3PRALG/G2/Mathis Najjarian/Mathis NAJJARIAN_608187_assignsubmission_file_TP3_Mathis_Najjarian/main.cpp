#include <iostream>
#include <random>
#include "Eleve.h"
#include "CompareNote.h"
#include "CompareNom.h"


// J'ai utilise google + chatGPT pour la partie generation aleatoire de chaines de caracteres
// notamment pour trouver mt19937 et uniform_int_distribution
void afficherEleves(const std::vector<Eleve>& eleves) {
    std::cout << "-------------------------------" << std::endl;
    for (auto iterateur = eleves.begin(); iterateur != eleves.end(); ++iterateur) {
        
        std::cout << "Eleve: " << iterateur->nom << ", Note: " << iterateur->note << std::endl;
        
    }
    std::cout << "-------------------------------" << std::endl;
}
std::string GenererNom(std::mt19937& rng) {
    std::uniform_int_distribution<int> longueurNom(1, 10);
    std::uniform_int_distribution<int> limitesMaj('A', 'Z');
    std::uniform_int_distribution<int> limitesMin('a', 'z');

    int len = longueurNom(rng);
    std::string nom;
    nom.push_back(limitesMaj(rng));
    for (int i = 0; i < len; ++i) {
        nom.push_back(limitesMin(rng));
    }
    return nom;
}

std::vector<Eleve> GenererEleves(int nombreEl, std::mt19937& rng) {
    std::uniform_int_distribution<int> noteDist(0, 20);
    std::vector<Eleve> v;
    for (std::size_t i = 0; i < nombreEl; ++i) {
        v.push_back(Eleve(GenererNom(rng), noteDist(rng)));
    }
    return v;
}

int main() {


    std::random_device rd;
    std::mt19937 rng(rd());

    std::vector<Eleve> eleves = GenererEleves(10, rng); 

	afficherEleves(eleves);

	// Tri note decroissante
    int compteur = 0;
    CompareNote NoteDecroi;
    NoteDecroi.ptr = &compteur;
    std::sort(eleves.begin(), eleves.end(), NoteDecroi);
	afficherEleves(eleves);
	std::cout << "Nombre de comparaisons pour le tri par note: " << compteur << std::endl;

	// Tri par ordre alphabetique 
	compteur = 0;
    CompareNom NomAlpha;
    NomAlpha.ptr = &compteur;
	std::sort(eleves.begin(), eleves.end(), NomAlpha);
	afficherEleves(eleves);
	std::cout << "Nombre de comparaisons pour le tri par nom: " << compteur << std::endl;

    
    return 0;
}

