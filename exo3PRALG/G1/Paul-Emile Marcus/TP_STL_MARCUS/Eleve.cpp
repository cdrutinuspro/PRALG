#include "Eleve.h"
#include <iostream>

Eleve::Eleve(string a, int b){
    nom = a;
    note = b;
}

string Eleve::getName() const{
    return nom;
}

int Eleve::getGrade() const{
    return note;
}

void Eleve::display() const {
    cout<<"Nom : "<<nom<<" //"<<" Note : "<<note<<endl;
}

