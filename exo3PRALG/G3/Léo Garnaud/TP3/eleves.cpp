#include "eleves.h"
#include <cassert>

Eleve::Eleve(string nom0, int note0){
    nom = nom0;
    note = note0;
}


void Eleve::affiche(){
    std::cout << nom << " : " << note << endl;
}
