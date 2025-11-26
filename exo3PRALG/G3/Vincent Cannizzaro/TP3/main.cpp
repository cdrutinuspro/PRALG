// #include<Imagine/Graphics.h>
// using namespace Imagine;
#include "Eleve.h"
#include <iostream>
#include <vector>
using namespace std;

int number_of_student = 20;

void print_vector(std::vector<Eleve> groupe) {
    for (int i = 0; i<groupe.size(); i++) {
        groupe[i].print();
    }
    std::cout<<std::endl;
}


int main() {
    // initRandom();
    std::vector<Eleve> groupe; // = {};
    for (int i = 0; i<number_of_student; i++) {
        int rand_grade = rand()%21 ; //intRandom(0,20);
        std::string rand_name ="";
        char majuscule = 'A';
        majuscule += rand()%26; //intRandom(0,25);
        rand_name.push_back(majuscule);
        int name_length = rand()%10; //intRandom(0,9);
        for (int i=0; i<name_length; i++) {
            char minuscule = 'a';
            minuscule += rand()%26 ; // intRandom(0,25);
            rand_name.push_back(minuscule);
        }
        Eleve new_student = Eleve(rand_name,rand_grade);
        groupe.push_back(new_student);
    }
    int compteur = 0;
    std::sort(groupe.begin(), groupe.end() ,CompareNom(&compteur,false)); //Noms croissants
    print_vector(groupe);
    std::cout<<"nombre de comparaison : "<<compteur<<"\n"<<std::endl;

    compteur = 0;
    std::sort(groupe.begin(), groupe.end() ,CompareNote(&compteur,false)); //Notes croissantes
    print_vector(groupe);
    std::cout<<"nombre de comparaison : "<<compteur<<"\n"<<std::endl;

    compteur = 0;
    std::sort(groupe.begin(), groupe.end(), CompareNom(&compteur,true)); //Noms decroissants ( "reverse" la liste croissante aurait pu marcher aussi )
    print_vector(groupe);
    std::cout<<"nombre de comparaison : "<<compteur<<"\n"<<std::endl;

    compteur = 0;
    std::sort(groupe.begin(), groupe.end(), CompareNote(&compteur,true)); //Notes décroissantes ( idem )
    print_vector(groupe);
    std::cout<<"nombre de comparaison : "<<compteur<<"\n"<<std::endl;


    return 0;
}

