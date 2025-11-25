#include <iostream>
#include "Eleve.h"
Eleve::Eleve(std::string cara, int p) : nom(cara), note(p) {}

int Eleve::get_note() const {
        return note;
    }
std::string Eleve::get_nom() const {
        return nom;
    }

void Eleve:: display() const{
        std::cout<<"L'eleve s'appelle : "<< nom <<" et a obtenu "
                  << note <<std::endl;
}
