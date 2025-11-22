#ifndef ELEVE_H
#define ELEVE_H
#include <string>
using namespace std;

class Eleve
{
    string nom;
    int note;
public:
    // constructeurs
    Eleve();
    Eleve(string name, int grade);

    // getteurs
    string getnom() const;
    int getnote() const;

    // fonction afficher;
    void afficher() const;

};

class CompareNom {
public:
    int* ptr; // pointeur sur compteur

    CompareNom(int* p = nullptr) : ptr(p) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr != nullptr)
            ++(*ptr);
        return a.getnom() < b.getnom();
    }
};

class CompareNote {
public:
    int* ptr;

    CompareNote(int* p = nullptr) : ptr(p) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr != nullptr)
            ++(*ptr);
        return a.getnote() > b.getnote(); // tri décroissant
    }
};


#endif // ELEVE_H
