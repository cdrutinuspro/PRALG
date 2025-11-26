#pragma once

#include <vector>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Eleve{
    string nom;
    int note;
public:
    Eleve();
    string get_nom() const{
        return nom;
    }
    int get_note() const{
        return note;
    }

};

ostream& operator<<(ostream& str, Eleve e);

class CompareNom{
public:
    int* ptr;
    bool operator()(Eleve e1, Eleve e2) const {
        (*ptr)++;
        return e1.get_nom() < e2.get_nom();
    }
};

class CompareNote{
public:
    int* ptr;
    bool operator()(Eleve e1, Eleve e2) const {
        (*ptr)++;
        return e1.get_note() > e2.get_note();
    }
};
