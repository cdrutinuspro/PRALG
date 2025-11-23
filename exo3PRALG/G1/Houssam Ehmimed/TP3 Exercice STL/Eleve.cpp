#include "Eleve.h"
#include <iostream>
#include <vector>

void Eleve::set(int nouv_note){
    note = nouv_note;
}

int Eleve::get_note(){
    return note;
}

std::string Eleve::get_nom(){
    return nom;
}

Eleve::Eleve(std::string name, int grade){
    nom = name;
    note = grade;
}

void Eleve::afficher_eleve(){
    cout << "Le nom de l'eleve est " << nom << " et sa note est " << note << endl;
}

bool CompareNote::operator()(Eleve eleve1, Eleve eleve2) const{
    //Incrémentation du nombre de comparaison
    ++*ptr;
    //Tri décroissant
    return eleve1.get_note() >= eleve2.get_note();
}

CompareNote::CompareNote(int* p){
    ptr = p;
}

bool CompareNom::operator()(Eleve eleve1, Eleve eleve2) const{
    //Incrémentation du nombre de comparaison
    ++*ptr;
    //Tri décroissant
    return eleve1.get_nom() >= eleve2.get_nom();
}

CompareNom::CompareNom(int* p){
    ptr = p;
}

void afficher(vector<Eleve> Eleves){
    for (Eleve eleve : Eleves){
        eleve.afficher_eleve();
    }
}





















