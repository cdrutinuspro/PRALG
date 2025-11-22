#include "eleve.h"
#include <iostream>
using namespace std;



Eleve::Eleve() {}

Eleve::Eleve(string name, int grade){
    nom = name;
    note = grade;
}

string Eleve::getnom() const{
    return nom;
}

int Eleve::getnote() const{
    return note;
}

void Eleve::afficher() const{
    cout<<"nom : "<< nom <<", note : "<<note<<endl;
}
