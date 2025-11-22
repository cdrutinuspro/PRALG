#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Eleve {      
private:
    std::string nom;
    int note;

public:
    Eleve(const std::string& n, int nt);
    void setNom(const std::string& newNom);
    void setNote(int newNote);

    std::string getNom() const;
    int getNote() const;
};

void afficher(const std::string& titre, const std::vector<Eleve>& eleves);
void remplirClasse(std::vector<Eleve>& classe);

std::ostream& operator<<(std::ostream& os, const Eleve& e);

class CompareNom {
public:
    int* compteurNom_ptr;
    CompareNom(int* ptr) : compteurNom_ptr(ptr) {}
    bool operator()(const Eleve& a, const Eleve& b) {
        ++(*compteurNom_ptr);
        return a.getNom() < b.getNom();
    }
};

class CompareNote {
public:
    int* compteurNote_ptr;
    CompareNote(int* ptr) : compteurNote_ptr(ptr) {}
    bool operator()(const Eleve& a, const Eleve& b) {
        ++(*compteurNote_ptr);
        return a.getNote() > b.getNote();
    }
};
