#include "eleves.h"

Eleve::Eleve(std::string nom, int note)
{
    name = nom;
    grade = note;

}

std::string& Eleve::get_name(){
    return name;
}

int& Eleve::get_grade(){
    return grade;
}
