#pragma once
#include <iostream>
#include <string> 
#include <cctype>
#include <utility>

class Eleve {
    std::string nom;
    int note;
    
    public:
    Eleve(int note, std::string nom);
    void display() const;
    std::string getNom();
    int getNote();
};

struct CompareNom{
    int* ptr;

    CompareNom(int* compteur);
    bool operator()(Eleve eleve1, Eleve eleve2);
};

struct CompareNote{
    int* ptr;

    CompareNote(int* compteur);
    bool operator()(Eleve eleve1, Eleve eleve2);
};