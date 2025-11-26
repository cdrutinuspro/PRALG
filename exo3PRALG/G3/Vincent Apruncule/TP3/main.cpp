// #include <QCoreApplication>
#include <iostream>
#include "eleves.h"
#include <vector>


//fonction pour générer un nouveaux nom de longeur aléatoire
std::string generate_name(){
    std::string name = "";
    char first = 'A' + rand()%26;
    name+= first;
    int num_letter =1 + rand()%9;
    for (int i=0; i< num_letter;i++){
        char letter = 'a' + rand()%26;
        name+=letter;
    }
    return name;
}

//fonction pour afficher un les differensts noms et notes d'un vecteur d'élèves
void display_student(std::vector<Eleve>& eleves){
    for (Eleve& eleve : eleves){
        std::cout<<eleve.get_name()<<" "<<eleve.get_grade() <<std::endl;
    }

}

int main()
{
    srand(time(0));
    std::cout<<generate_name()<<std::endl;

    //création du vecteur d'élèves
    std::vector<Eleve> v ;
    //initialisation du pointeur qui sert à compter
    int ini_name = 0;
    int ini_grade = 0;
    int* compteur_name = &ini_name;
    int* compteur_grade = &ini_grade;


    //initialisation des foncteurs
    CompareNom comp_nom(compteur_name);
    CompareGrade comp_note(compteur_grade);

    for (int i = 0; i<10;i++){
        int note = rand()%21;
        std::string name = generate_name();
        Eleve student(name,note);
        v.push_back(student);
    }

    std::sort(v.begin(), v.end(), comp_nom);
    display_student(v);
    std::cout<< *compteur_name<< std::endl;
    std::sort(v.begin(), v.end(), comp_note);
    display_student(v);
    std::cout<< *compteur_grade<< std::endl;
    return 0;
}
