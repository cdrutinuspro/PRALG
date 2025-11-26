#pragma once
#include <string>
#include <vector>
using namespace std;

class Eleve
{
private:
    string nom;
    int notes;

public:
    Eleve(const string &nom);
    void ajouterNote(float note);
    int getNotes() const;
    string getNom() const;
};

class CompareNom
{
public:
    int *c_N = new int{0};
    bool operator()(const Eleve &e1, const Eleve &e2) const;
};

class CompareNotes
{
public:
    int *c_G = new int{0};
    bool operator()(const Eleve &e1, const Eleve &e2) const;
};