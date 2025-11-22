#pragma once
#include <string>
#include <vector>

using namespace std;

class Eleve
{
    int grade = -1;
    string name;

public:
    Eleve(string n);
    void setGrade(int g);
    int getGrade() const;
    string getName() const;
};

class GradeComparator
{
    const vector<Eleve> liste_eleves;

public:
    int *ptr = 0;
    GradeComparator(const vector<Eleve> L) : liste_eleves(L) {}
    bool operator()(int i, int j) const
    {
        ++*ptr;
        return liste_eleves[i].getGrade() > liste_eleves[j].getGrade();
    };
};

class NameComparator
{
    const vector<Eleve> liste_eleves;

public:
    int *ptr = 0;
    NameComparator(const vector<Eleve> L) : liste_eleves(L) {}
    bool operator()(int i, int j) const
    {
        ++*ptr;
        return liste_eleves[i].getName() < liste_eleves[j].getName();
    };
};

void afficher_classe(const vector<Eleve> &classe);

void afficher_classe_ordre(const vector<Eleve> &classe, int ordre[], int taille, int n_comparaison);
