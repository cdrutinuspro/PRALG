#include <iostream>
#include <string> 
using namespace std;

class Eleve {
    string nom;
    int note;

public:
    Eleve(string name, int grade);
    void afficher() const;
    string getNom() const;
    int getNote() const;
    void setNom(string n);
    void setNote(int n);
};

class CompareNotes {
    int* ptr;
public:
    CompareNotes(int* compteur);
    bool operator()(const Eleve& a, const Eleve& b) const;
    };

class CompareNoms{
    int* ptr;
public:
    CompareNoms(int* compteur);
    bool operator()(const Eleve& a, const Eleve& b) const;
};

void afficher_vecteur(const vector<Eleve>& vect);
