#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>



class eleve {
    public:
    std::string nom;
    int note;
    eleve(std::string NOM, int NOTE);
};

class CompareNom {
    public:
    int * ptr;
    CompareNom(int* compt);
    bool operator()(const eleve& a, const eleve& b);
};

class CompareNote {
    public:
    int * ptr;
    CompareNote(int* compt);
    bool operator()(const eleve& a, const eleve& b);
};