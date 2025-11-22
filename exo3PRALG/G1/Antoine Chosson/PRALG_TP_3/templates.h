#pragma once
#include <string>

class Eleve {
    std::string name; 
    int note; 
public : 
    // Constructeur 
    Eleve(std::string name, int note);
    //Destructeur
    ~Eleve();
    // Constructeur par copie 
    Eleve(const Eleve& E);
    // Get Method for name 
    std::string get_name() ;
    // Get Methode for grade 
    int get_grade();
};

class CompareNote {
    int* ptr; 
public :
    // contructeur 
    CompareNote(int* counter);
    // Opérateur de comparaison 
    bool operator()(Eleve eleve1, Eleve eleve2); 
};

class CompareNom {
    int* ptr; 
public : 
    // contructeur 
    CompareNom(int* counter);
    // Opérateur de comparaison 
    bool operator()(Eleve eleve1, Eleve eleve2); 
};