#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <iostream>
#include <vector>

class Eleve {
private:
    std::string nom;
    int note;

public:
    Eleve(const std::string& n = "", int no = 0);

    std::string getNom() const;
    int getNote() const;
    void afficher() const;
};


struct CompareNom {
    int* ptr;
    CompareNom(int* p = nullptr) : ptr(p) {}

    bool operator()(const Eleve& a, const Eleve& b) const;
};

struct CompareNote {
    int* ptr;
    CompareNote(int* p = nullptr) : ptr(p) {}

    bool operator()(const Eleve& a, const Eleve& b) const;
};

Eleve genererEleveAleatoire();
void afficherVector(const std::vector<Eleve>& v);




#endif // ELEVE_H
