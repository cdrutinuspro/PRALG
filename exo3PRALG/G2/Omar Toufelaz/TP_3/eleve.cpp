#include "eleve.h"
#include <iostream>
#include <iomanip>

//Question 1
Eleve::Eleve(std::string name,int grade){
    nom=name;
    note=grade;
}
void Eleve::SetNote(int grade){
    note=grade;
}
int Eleve::GetNote() const{
    return note;
}
std::string Eleve::GetNom()const{
    return nom;
}
