#pragma once
#include <iostream>
using namespace std;
#include <vector>

class Eleve{
    std::string nom;
    int note;
public:
    Eleve(){note=0; nom="";}
    Eleve(string nom0, int note0);
    string getnom(){return nom;}
    int getnote(){return note;}
    void affiche();
};

class CompareNote{
public:
    int* ptr;
    bool operator()(Eleve eleve1, Eleve eleve2) const {
        ++*ptr;
        return eleve1.getnote() > eleve2.getnote();}
};

class CompareNom{
public:
    int* ptr;
    bool operator()(Eleve eleve1, Eleve eleve2) const{
        ++*ptr;
        return (eleve1.getnom().compare(eleve2.getnom())<0);}
};
