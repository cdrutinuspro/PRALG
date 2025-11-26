#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;
#include <string>


class Eleve {
    string nom;
    int note;
public:
    Eleve(){}
    ~Eleve();
    int getNote() const;
    void setNote(int d);
    string getNom() const;
    void setNom(string d);
    void displaycout(string indent = " : ") const;
};

class CompareNom {
    const vector<Eleve>& classe;
public:
    int* ptr;
    CompareNom(const vector<Eleve>& c) : classe(c) {}
    bool operator()(int i, int j) const;
};

class CompareNote {
    const vector<Eleve>& classe;
public:
    int* ptr;
    CompareNote(const vector<Eleve>& c) : classe(c) {}
    bool operator()(int i, int j) const;
};

class CompareNoteNom {
    const vector<Eleve>& classe;
public:
        int* ptr;
    CompareNoteNom(const vector<Eleve>& c) : classe(c) {}
    bool operator()(int i, int j) const;
};
