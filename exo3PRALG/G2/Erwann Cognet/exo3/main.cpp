#include "Eleve.h"
#include <random>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


const std::string alphabet  = "azertyuiopqsdfghjklmwxcvbn";
const std::string ALPHABET  = "AZERTYUIOPQSDFGHJKLMWXCVBN";

std::mt19937& rng() {
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

std::string RandomName() {
    static std::uniform_int_distribution<int> dist26(0, 25);
    static std::uniform_int_distribution<int> distLen(0, 10);

    std::string name;
    name.push_back(ALPHABET[dist26(rng())]);
    int lengthName = distLen(rng());
    for (int i = 0; i < lengthName; ++i)
        name.push_back(alphabet[dist26(rng())]);
    return name;
}

int RandomGrade() {
    static std::uniform_int_distribution<int> distGrade(0, 20);
    return distGrade(rng());
}

int main() {
    // Creation du vecteur aléatoire
    std::vector<Eleve> eleves;
    eleves.reserve(10);
    for (int i = 0; i < 10; ++i)
        eleves.emplace_back(RandomName(), RandomGrade());
    for (Eleve e : eleves)
        e.show();
    std::cout<<"    "<<std::endl;

    // Liste triée par nom
    int compteur1 = 0;
    CompareNom c1(&compteur1);
    std::sort(eleves.begin(), eleves.end(), c1);
    for (Eleve e : eleves)
        e.show();
    std::cout<< "nombre de tri : " << compteur1 <<std::endl;
    std::cout<<" "<<std::endl;

    // Liste triée par note
    int compteur2 = 0;
    CompareNom c2(&compteur2);
    std::sort(eleves.begin(), eleves.end(), c2);
    for (Eleve e : eleves)
        e.show();
    std::cout<< "nombre de tri : " << compteur2 <<std::endl;

}
