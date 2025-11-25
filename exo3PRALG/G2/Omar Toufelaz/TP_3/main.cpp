/**
 * @file main.cpp
 * @brief Programme principal : génération, tri et affichage d'élèves.
 *
 * Ce programme :
 * - génère un vecteur d'élèves avec noms et notes aléatoires ;
 * - trie les élèves selon deux critères (nom alphabétique et note décroissante) ;
 * - affiche les résultats et le nombre de comparaisons effectuées.
 */
// #include <Imagine/Images.h>
// #include <Imagine/Graphics.h>
#include <iostream>

// using namespace Imagine;
using namespace std;

// typedef Image<byte> Img;
#include <random>

#include "eleve.h"

//Question 2

/**
 * @brief Génère un nom aléatoire : une majuscule suivie de 1 à 10 minuscules.
 * @return Nom aléatoire sous forme de chaîne de caractères.
 */
std::string gen_nom() {//fonction qui génere un nom aléatoirement comme décrit dans l'ennoncé
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> len_dist(1, 10);
    std::uniform_int_distribution<int> up(0, 25), low(0, 25);

    int len = len_dist(rng);
    std::string s;
    s.reserve(1 + len);
    s.push_back(char('A' + up(rng)));
    for (int i = 0; i < len; ++i)
        s.push_back(char('a' + low(rng)));
    return s;
}

//Question 4

/**
 * @brief Affiche la liste des élèves à l'aide d'itérateurs.
 * @param eleves Vecteur d'élèves à afficher.
 */
void afficherEleves(std::vector<Eleve>& eleves){//fonction quiaffiche une liste d'élève
    std::vector<Eleve>::const_iterator it = eleves.begin();
    for (; it!=eleves.end();++it)
        std::cout<<it->GetNom()<<" : "<<it->GetNote()<< std::endl;
}

int main() {

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> nb_dist(1, 20);
    std::uniform_int_distribution<int> note_dist(0, 20);

    int number_eleve = nb_dist(rng);
    std::vector<Eleve> eleves;
    eleves.reserve(number_eleve);


    for (int i = 0; i < number_eleve; ++i) {
        std::string nom = gen_nom();
        int note = note_dist(rng);
        eleves.emplace_back(nom, note);
    }

    //Question 4

    int cptNom = 0;
    int cptNote = 0;//Question 6

    std::cout << "Tri alphabetique" << std::endl;
    std::sort(eleves.begin(), eleves.end(), CompareNom(&cptNom));//Question7
    afficherEleves(eleves);
    std::cout << "Nombre de comparaisons (nom) : " << cptNom << std::endl;


    std::cout << "Tri par note decroissante" << std::endl;
    std::sort(eleves.begin(), eleves.end(), CompareNote(&cptNote));//Question 7
    afficherEleves(eleves);
    std::cout << "Nombre de comparaisons (note) : " << cptNote << std::endl;


    return 0;
}
