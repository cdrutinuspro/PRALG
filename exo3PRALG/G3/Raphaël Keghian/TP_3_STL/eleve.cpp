#include "eleve.h"

Eleve::Eleve(string n, int g){
    name = n;
    grade = g;
}

string& Eleve::get_name(){
    return name;
}

int& Eleve::get_grade(){
    return grade;
}
