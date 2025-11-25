#pragma once
#include <string>
// #include <Imagine/Graphics.h>
#include <cassert>
#include <ostream>
// using namespace Imagine;
using namespace std;

class Eleve{
    string nom;
    int note;

public:
    //Constructeurs
    Eleve();
    Eleve(string nom0, int note0);

    //Renvoie la note de l'eleve
    int get_note() const;

    //Change la note de l'eleve
    void set_note(const int note0);

    //Renvoie le nom de l'eleve
    string get_nom() const;


};

class CompareNom{
    int* ptr;

public:
    bool operator()(const Eleve& a, const Eleve& b) const;
    void set_compteur(int & compteur);
};

class CompareNote{
    int* ptr;

public:
    bool operator()(const Eleve& a, const Eleve& b) const;
    void set_compteur(int & compteur);

};
