#include "eleve.h"
// #include <Imagine/Graphics.h>
#include <cstdlib>
#include <iostream>


using namespace std;

void Eleve::random_init(){
    char maj_code = 'A' + rand()%('Z'-'A'+1); //code ASCII pour une majuscule
    nom += maj_code;
    int nb_min = 1+rand()%10; // nombre de minuscules dans le nom
    for(int i=0;i<nb_min;i++){
        int min_code = 'a' + rand()%('z'-'a'+1); //code ASCII pour une minuscule
        nom += min_code;
        }
    note = rand()%21;
}

void Eleve::show(){
    cout<<nom<< ':'<<note<<endl;
}

string Eleve::get_nom(){
    return nom;
}

int Eleve::get_note(){
    return note;
}



bool CompareNom::operator()(Eleve eleve1,Eleve eleve2) const {
    ++*ptr;
    return eleve1.get_nom()<eleve2.get_nom();
}

void CompareNom::set_ptr(int & compteur){
    ptr = &compteur;
}

bool CompareNote::operator()(Eleve eleve1,Eleve eleve2) const {
    ++*ptr;
    return eleve1.get_note()>eleve2.get_note();
    }

void CompareNote::set_ptr(int & compteur){
    ptr = &compteur;
}
