#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Eleve{
    string nom_eleve;
    int note_eleve;
public:
    // Constructeur
    Eleve(string nom,int note);
    // Méthode d'affichage
    string nom() const; 
    int note() const;
    // Dans le cas où on s'est trompé de la note
    void modifie_note(int note);
};

class CompareNom{
    int* cnt_ptr;
public:
    CompareNom(int& cnt);
    bool operator()(Eleve eleve1,Eleve eleve2) const;
};

class CompareNote{
    int* cnt_ptr;
public:
    CompareNote(int& cnt);
    bool operator()(Eleve eleve1,Eleve eleve2) const;
};

void affiche(const vector<Eleve>& eleves);
