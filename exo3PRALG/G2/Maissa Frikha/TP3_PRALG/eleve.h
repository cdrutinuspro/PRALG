#pragma once
#include <vector>
#include <string>
using namespace std;

class Eleve{
    string name;
    int note;
public:
    Eleve(string name0, int note0);
    string getName() const { return name; }
    int getNote() const { return note; }
};
void afficherEleves(const std::vector<Eleve>& vec);
using EleveIterator = vector<Eleve>::iterator;
using EleveConstIterator = vector<Eleve>::const_iterator;

struct CompareName {
    int* ptr; // pointeur vers un compteur
    CompareName(int* compteur = nullptr) : ptr(compteur) {}
    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++*ptr;
        return a.getName() < b.getName();
    }
};


struct CompareNote {
    int* ptr; // pointeur vers un compteur
    CompareNote(int* compteur = nullptr) : ptr(compteur) {}
    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++*ptr;
        return a.getNote() < b.getNote();
    }
};

