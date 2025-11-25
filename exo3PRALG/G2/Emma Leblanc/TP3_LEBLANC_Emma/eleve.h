#pragma once
#include <vector>
#include <string>
using namespace std;

class Eleve {
    string nom;
    int note;
public:
    void random_init();
    void show();
    string get_nom();
    int get_note();
};

class CompareNom{
    int* ptr;
public:
    bool operator()(Eleve eleve1,Eleve eleve2) const;
    void set_ptr(int & compteur);
};

class CompareNote{
    int* ptr;
public:
    bool operator()(Eleve eleve1,Eleve eleve2) const;
    void set_ptr(int & compteur);
};
