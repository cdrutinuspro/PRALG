#include "Eleve.h"

Eleve::Eleve(string name0,int grade0){
    name=name0;
    grade=grade0;
}

Eleve::Eleve(const Eleve& student){
    name=student.name;
    grade=student.grade;
}

