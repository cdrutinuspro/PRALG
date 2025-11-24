#include "eleve.h"

Eleve :: Eleve(string nm, int grd){
    name = nm;
    grade = grd;
}

Eleve :: Eleve (const Eleve& elv){
    name = elv.name;
    grade = elv.grade;
}

void Eleve :: operator= (const Eleve& elv){
    name = elv.name;
    grade = elv.grade;
}

void Eleve :: affiche(){
    cout << name << "   |   Note : " << grade << endl;
}