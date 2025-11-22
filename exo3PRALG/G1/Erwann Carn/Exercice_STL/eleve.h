#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Eleve{
    string nom;
    int note = 0;
public:
    Eleve(string nom_el, int not_el);
    ~Eleve() = default;
    friend ostream& operator<<(ostream& os, const Eleve& e);
    int getNote() const;
    string getNom() const;
};

char lettre_minuscule();

char lettre_majuscule();

void generate(vector<Eleve>& out, int max_count);
