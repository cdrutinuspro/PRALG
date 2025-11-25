#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Eleve {
    std::string nom;
    int note;
    public:
    Eleve (std::string n, int no, bool random = false);
    std::string getNom() const;
    int getNote() const;
};

class CompareNote {
    int* ptr;
    public:
    CompareNote(int& compteur) : ptr(&compteur) {};
    bool operator() (const Eleve& e_1, const Eleve& e_2) {
        ++*ptr;
        return e_1.getNote() > e_2.getNote(); 
    };
};

class CompareNom {
    int* ptr;
    public:
    CompareNom(int& compteur) : ptr(&compteur) {};
    bool operator() (const Eleve& e_1, const Eleve& e_2) { 
        std::string nom1 = e_1.getNom();
        std::string nom2 = e_2.getNom();
        ++*ptr;
        for (int i = 0; i < nom1.size() && i < nom2.size(); i++){
            if (nom1[i] != nom2[i]){
                return nom1[i] < nom2[i];
            }
        }
        return nom1.size() < nom2.size();
    };
};

void DisplayEleves(const std::vector<Eleve>& eleves);