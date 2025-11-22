#include "Eleve.h"
#include <iostream>

Eleve::Eleve(std::string name, int mark){
    nom=name;
    note=mark;};

Eleve::~Eleve(){};

void Eleve::setmark(int mark){
    note=mark;
};

void Eleve::setname(std::string name){
    nom=name;
};

int Eleve::getmark() const{
    return note;
};

std::string Eleve::getname() const{
    return nom;
};


void affichage(const std::vector<Eleve>& eleve){
    std::cout << "Vecteur Eleve : " << "\n";
    for (int i = 0; i < eleve.size(); i++){
        std::cout << eleve[i].getname() <<" : " << eleve[i].getmark() << "\n";
    };
};


std::string randomName() {
    int len = 1 + rand() % 10; //entre 1 et 10 lettres minuscules
    std::string name;
    name += 'A' + rand() % 26; // première lettre majuscule

    for (int i = 0; i < len; ++i) {
        name += 'a' + rand() % 26; // lettres minuscules
    };
    return name;
}
