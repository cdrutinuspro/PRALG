#pragma once
#include <iostream>
using namespace std;


class Eleve{
    int note;
    string nom;

public:
    Eleve(int grade, string name);
    Eleve();    // Creer un Eleve avec nom et note aleatoire
    int getNote() const;
    string getNom() const;

};

class CompareNom{
    int* ptr;
public:
    CompareNom(int* compteur);
    bool operator()(Eleve e1, Eleve e2) const;
};

class CompareNote{
    int* ptr;
public:
    CompareNote(int* compteur);
    bool operator()(Eleve e1, Eleve e2) const;
};

const char MajAlpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char Alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

string RandomName();

