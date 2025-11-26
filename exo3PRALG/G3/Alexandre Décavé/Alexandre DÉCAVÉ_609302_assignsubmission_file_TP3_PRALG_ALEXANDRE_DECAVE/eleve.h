#pragma once
#include <iostream>
#include <cassert>
#include <list>
#include <stdexcept>
#include <queue>
using namespace std;


class Eleve {
    std::string name;
    int note;
public:

    Eleve(std::string aName, int aNote);

    ~Eleve();

    void SetNote(int d);

    int GetNote() const;

    void SetName(std::string str);

    std::string GetName() const;
};

//foncteur pour comparer les notes des élèves, je me suis inspiré des slides
//je n'étais pas sûr de savoir s'il fallait tout écrire dans le header
//ou s'il fallait faire comme une classe normale. Selon moi, c'est les 
//templates qui doivent être écrits dans le header d'après le cours
class CompareNote {
public:
    int* ptr; //comme demandé pour incrémenter le compteur
    bool operator()(Eleve& eleve1, Eleve& eleve2);
};

//Foncteur pour comparer les noms des élèves, même façon de faire que CompareNote
class CompareName {
public:
    int* ptr;
    bool operator()(Eleve& eleve1, Eleve& eleve2);
};

void AfficheEleves(const std::vector<Eleve>& groupe_eleves);
//de même que pour les foncteurs, on met "&" pour ne pas tout copier