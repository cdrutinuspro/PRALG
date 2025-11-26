#pragma once 
#include <iostream>
#include <string>
#include <cctype>
#include <utility>

class Eleve
{
    public:
        Eleve(int note, std :: string nom);
        void display();
        std::string getNom();
        int getNote();

    private:
        int note;
        std :: string nom;
};

struct CompareNote
{
    CompareNote(int* compteur);
    bool operator()(Eleve eleve1, Eleve eleve2);

    int* ptr;
};

struct CompareNom
{
    CompareNom(int* compteur);
    bool operator()(Eleve eleve1, Eleve eleve2);

    int* ptr;
};
