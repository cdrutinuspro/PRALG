#include "eleve.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

Eleve::Eleve() {
    nom = "Lambda";
    note = 10;
}

Eleve::Eleve(string nom1, int note1){
    nom =  nom1;
    note = note1;
}

string Eleve::getNom()const{
    return nom;
}

int Eleve::getNote()const{
    return note;
}

void Eleve::setNote(int new_note) {
    note = new_note;
}


std::ostream& operator<<(std::ostream& os, const Eleve& eleve){
    os << eleve.getNom() << " : " << eleve.getNote() << endl;
    return os;
}



Eleve random_eleve(){
    int length = 1 + (rand()%10);
    string nom;
    nom += ('A'+(rand()%26));
    for (int i=0; i<length; i++){
        nom += 'a'+(rand()%26);
    }
    int note = rand()%21;
    return Eleve(nom, note);
}


CompareNom::CompareNom(){
    ptr = new int;
    *ptr = 0;
    to_delete = true;
}

CompareNote::CompareNote(){
    ptr = new int;
    *ptr = 0;
    to_delete = true;
}


CompareNom::CompareNom(int* cmp){
    ptr = cmp;
    to_delete = false;
}

CompareNote::CompareNote(int* cmp){
    ptr = cmp;
    to_delete = false;
}


CompareNom::~CompareNom(){
    if (to_delete){
        delete [] ptr;
    }
}

CompareNote::~CompareNote(){
    if (to_delete){
        delete [] ptr;
    }
}



bool CompareNom::operator()(Eleve eleve1, Eleve eleve2){
    ++*ptr;
    return (eleve1.getNom().compare(eleve2.getNom()) <= 0);
}


bool CompareNote::operator()(Eleve eleve1, Eleve eleve2){
    ++*ptr;
    return (eleve1.getNote()>=eleve2.getNote());
}



