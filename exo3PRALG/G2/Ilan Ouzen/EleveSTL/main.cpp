#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Eleve.h"
#include "CompareNote.h"
#include "CompareNom.h"

int genererNote(){
    return rand() %21;
}

std::string generer_alea_nom(){
    int longueur= rand() % 10 +1;
    std::string nom;
    char majuscule = 'A'+ rand() %26;
    nom+=majuscule;

    for (int i=0; i<longueur;i++){
        char minuscule = 'a'+ rand() % 26 ;
        nom+=minuscule;
    }
    return nom;
}
void afficherVector(const std::vector<Eleve>&v){
    for (const Eleve&eleve:v){
        eleve.display();
    }
}

int main()
{   srand(time(NULL));  // Initialisation du générateur aléatoire
    int nb_eleves=15;
    std::vector<Eleve> v;
    for (int i=0; i<nb_eleves;i++){
        v.push_back(Eleve(generer_alea_nom(), genererNote()));
    }
    std::cout<<"Liste initiale des eleves : "<<std::endl;  // Affichage de la liste initiale
    afficherVector(v);
    std::cout<<std::endl;
    int compteur=0; // Définition du compteur

    std::cout<<"Tri par ordre alphabetique"<<std::endl;
    sort(v.begin(), v.end(), CompareNom(&compteur)); // Passage du pointeur
    afficherVector(v); // Affichage arès le tri par ordre alphabétique
    std::cout<<std::endl;
    std::cout<<"Le nombre de comparaisons effectuees, par nom pour l'ordre alphabetique vaut : "<<compteur<<std::endl;
    std::cout<<std::endl;


    compteur=0; // Réinitialisation du compteur
    std::cout<<"Tri par ordre decroissant"<<std::endl;
    sort(v.begin(), v.end(), CompareNote(&compteur));
    afficherVector(v);
    std::cout<<std::endl;
    std::cout<<"Le nombre de comparaisons effectuees, par note pour l'ordre decroissant vaut : "<<compteur<<std::endl;
}
