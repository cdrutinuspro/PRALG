#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;


class Eleve
{
public:
    int note;
    string nom;
    Eleve();
    Eleve(int note0, string nom0);
    void afficher();

};

class CompareNom{
public:
    int* ptr;
    CompareNom(int* compteur = nullptr) : ptr(compteur) {}
    bool operator()(Eleve e1, Eleve e2) const;
};

class CompareNote{
public:
    int* ptr;
    CompareNote(int* compteur = nullptr) : ptr(compteur) {}
    bool operator()(Eleve e1, Eleve e2) const;
};

Eleve random_eleve();


