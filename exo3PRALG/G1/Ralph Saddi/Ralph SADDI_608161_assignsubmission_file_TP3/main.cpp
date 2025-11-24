// #include <QCoreApplication>
#include <iostream>
#include "eleves.h"
#include <vector>

using namespace std;



std::string rand_name(){
    std::string nom = "";
    char f = 'A' + rand()%26;
    nom+= f;
    int num =1 + rand()%9;
    for (int i=0; i< num;i++){
        char l = 'a' + rand()%26;
        nom+=l;
    }
    return nom;
}


void display(std::vector<Eleve>& eleves){
    for (Eleve& eleve : eleves){
        std::cout<<eleve.get_name()<<" "<<eleve.get_grade() <<std::endl;
    }

}

int main()
{
    srand(time(0));
    std::cout<<rand_name()<<std::endl;

    //création du vecteur d'élèves
    std::vector<Eleve> v ;

    int ini_n = 0;
    int ini_g = 0;
    int* counter_n = &ini_n;
    int* counter_g = &ini_g;


    //foncteurs
    CompareNom comp_nom(counter_n);
    CompareGrade comp_note(counter_g);

    for (int i = 0; i<10;i++){
        int note = rand()%21;
        std::string nom = rand_name();
        Eleve student(nom,note);
        v.push_back(student);
    }

    std::sort(v.begin(), v.end(), comp_nom);
    std::cout << "Affichage par ordre alphabétique" << std::endl;
    display(v);
    std::cout << "Nombre de comparaisons : " << *counter_n << std::endl;

    std::sort(v.begin(), v.end(), comp_note);
    std::cout << "Affichage par notes décroissantes" << std::endl;
    display(v);
    std::cout << "Nombre de comparaisons : " << *counter_g << std::endl;

    return 0;
}
