#pragma once
#include <string>
#include <vector>

class Eleve {
    std::string nom;
    int note;
public :
    Eleve(const std::string& nom, int note);
    std::string getNom() const;
    int getNote() const;
    void setNote(int n);
};

class CompareNom {
    int* ptr;
public :
    CompareNom(int* p);
    bool operator()(const Eleve& a, const Eleve& b) const;
};

class CompareNote {
    int* ptr;
public :
    CompareNote(int* p);
    bool operator()(const Eleve& a, const Eleve& b) const;
};