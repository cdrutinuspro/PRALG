#include <iostream>
#include <string> 
#include <vector>
#include "eleves.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Eleve::Eleve(string name, int grade){
    nom=name;
    note=grade;
}

void Eleve::afficher() const{
  std::cout << nom << " " << note;

}

string Eleve::getNom() const{
    return nom;
}

int Eleve::getNote() const{
    return note;
}

void Eleve::setNom(string n){
    nom=n;
}

void Eleve::setNote(int n){
    note=n;
}

CompareNoms::CompareNoms(int* compteur) : ptr(compteur) {}

CompareNotes::CompareNotes(int* compteur) : ptr(compteur) {}

bool CompareNotes::operator()(const Eleve& a, const Eleve& b) const{
    ++(*ptr);
    return a.getNote()>b.getNote();
}

bool CompareNoms::operator()(const Eleve& a, const Eleve& b) const{
    ++(*ptr);
    return a.getNom() < b.getNom();  
    }
    

