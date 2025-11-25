#include "eleve.h"
#include <iostream>
#include <vector>
#include <random> // Pour la génération aléatoire
#include <array> 
#include <algorithm>
#include <ctime> //Pour initialiser le générateur de nombres aléatoires
#include <vector>

int genererNote(){
    return rand() % 21;
}

std::string genererNom(){
    std::string nom = "";
    nom += (char)('A' + rand() % 26);

    int longueur = 1+ rand() % 9 ; // Longeur totale du nom entre 2 et 10
    for (int i = 0 ; i < longueur ; i ++ ){
        nom+= (char)('a' + rand() % 26);
    }
    return nom;
}

void display_vector(std::vector<Eleve> eleves)
{
    for (int i=0; i<eleves.size(); i++)
        eleves[i].display();
}


int main(){

    int compteur = 0 ; 
    std::vector<Eleve> eleves ; 
    int nb_eleves ; 
    std::cout << "Combien d'eleves generer ? " ;
    std::cin >> nb_eleves ;
    for (int i = 0 ; i < nb_eleves ; i ++ ){
        eleves.emplace_back(genererNote(), genererNom());
    }
    
    
    std::sort(eleves.begin(), eleves.end(), CompareNote(&compteur));
    display_vector(eleves);
    std :: cout << "Le nombre de comparaisons effecutees est: " << compteur << "." << std :: endl;

    return 0;
}