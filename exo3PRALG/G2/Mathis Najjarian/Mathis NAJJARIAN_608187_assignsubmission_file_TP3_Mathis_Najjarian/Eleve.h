#pragma once
#include <string>
#include <iostream>

class Eleve
{
public:
    int note;
    std::string nom;

    Eleve(std::string nom, int note);
    void afficher();
};
