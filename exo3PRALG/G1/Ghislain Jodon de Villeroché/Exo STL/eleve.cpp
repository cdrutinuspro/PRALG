#include "eleve.h"

Eleve::Eleve(int grade, string name){
    nom = name;
    note = grade;
}

Eleve::Eleve(){
    nom = RandomName();
    note = rand()%21;
}


int Eleve::getNote() const{
    return note;
}

string Eleve::getNom() const{
    return nom;
}

CompareNom::CompareNom(int* compteur){
    ptr = compteur;
}

bool CompareNom::operator()(Eleve e1, Eleve e2) const{
    *ptr+=1;
    return e1.getNom() <= e2.getNom();
}

CompareNote::CompareNote(int* compteur){
    ptr = compteur;
}

bool CompareNote::operator()(Eleve e1, Eleve e2) const{
    *ptr+=1;
    return e1.getNote() >= e2.getNote();
}

string RandomName(){
    int nameLength = rand()%9;
    nameLength++;
    string name;
    name += MajAlpha[rand()%26];
    for (int i = 0; i<nameLength-1;i++)
        name += Alpha[rand()%26];
    return name;
}
