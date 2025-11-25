#include "Eleve.h"
#include <iomanip>


// Constructeurs et destructeurs
Eleve::Eleve(std::string n, int g):
    name(n), grade(g)
{

}

Eleve::Eleve(const Eleve& other){
    name = other.name;
    grade = other.grade;
}

Eleve::~Eleve(){

}


// Getters et setters
std::string Eleve::get_name() const {
    return name;
}

int Eleve::get_grade() const {
    return grade;
}

void Eleve::set_name(std::string other_name){
    name = other_name;
}

void Eleve::set_grade(int other_grade){
    grade = other_grade;
}


//Autres
void Eleve::show(){
    std::cout<< "Nom :" << name << "  |  Note : " << grade << std::endl;

}
