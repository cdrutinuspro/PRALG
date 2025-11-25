#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <iostream>

using namespace std;

class Eleve {
private:
    string nom;
    int note;

public:
    // Constructeur
    Eleve(string nom_eleve = "", int note_eleve = 0);


    // Foncions nécessaires de base
    string nomEleve() const;
    int noteEleve() const;
    void modifierNom(string n);
    void modifierNote(int n);

    void afficher() const;
};


// Ce sont les foncteurs
class CompareNom {
public:
    int* ptr;
    CompareNom(int* ptr_) : ptr(ptr_) {}
    bool operator()(const Eleve& e1, const Eleve& e2);
};

class CompareNote {
public:
    int* ptr;
    CompareNote(int* ptr_) : ptr(ptr_) {}
    bool operator()(const Eleve& e1, const Eleve& e2);
};

void afficherVecteur(const vector<Eleve>& eleves);

#endif // ELEVE_H
