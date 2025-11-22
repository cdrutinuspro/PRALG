#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


class Eleves {
public:
    std::string name;
    int mark;

//constructeur
    Eleves(const string& n = "", int m = 0);
};




struct CompareNom {
public:
    int* ptr;
    CompareNom(int* p = nullptr);
    bool operator()(const Eleves& e1, const Eleves& e2) const ;
};

struct CompareNote {
public:
    int* ptr;
    CompareNote(int* p = nullptr);

    bool operator()(const Eleves& e1, const Eleves& e2) const ;
};


std::vector<Eleves> generate (int m);
void afficher_tri_nom(std::vector<Eleves> v, int* compteur);
void afficher_tri_note(std::vector<Eleves> v, int*compteur);
