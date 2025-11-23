#ifndef MATRICE_H
#define MATRICE_H

#endif // MATRICE_H

// #include<Imagine/Graphics.h>
// using namespace Imagine;
#include<string>
using namespace std;

class Eleve{
    std::string nom;
    int note;
public :
    void set(int nouv_note);
    int get_note();
    std::string get_nom();
    Eleve(std::string name, int grade);
    void afficher_eleve();
};

class CompareNote{
    int* ptr;
public :
    CompareNote(int* p);
    bool operator()(Eleve eleve1, Eleve eleve2) const;
};

class CompareNom{
    int* ptr;
public:
    CompareNom(int* p);
    bool operator()(Eleve eleve1, Eleve eleve2) const;
};

void afficher(std::vector<Eleve> Eleves);









