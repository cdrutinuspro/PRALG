#pragma once

#include <iostream>
#include <vector>
#include <string>


// Classe Eleve

class Eleve {
public:
    std::string nom;
    int note;

    Eleve(std::string n = "", int no = 0);
    void afficher() const;
};


// Foncteurs de comparaison

class CompareNom {
public:
    int* ptr;
    CompareNom(int* p = nullptr);
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const;
};

class CompareNote {
public:
    int* ptr;
    CompareNote(int* p = nullptr);
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const;
};


// Fonctions utilitaires

std::string nomAleatoire();
void afficherClasse(const std::vector<Eleve>& vec);
