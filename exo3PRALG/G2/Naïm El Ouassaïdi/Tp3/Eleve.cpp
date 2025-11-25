#include "Eleve.h"
#include <iostream>
#include <vector>
using namespace std;

Eleve::Eleve(){
    mark=0;
    name="";
}
Eleve::Eleve(string noun, int k){
    name=noun;
    mark=k;
}

Eleve::Eleve(const Eleve &student){
    mark=student.mark;
    name=student.name;
}


