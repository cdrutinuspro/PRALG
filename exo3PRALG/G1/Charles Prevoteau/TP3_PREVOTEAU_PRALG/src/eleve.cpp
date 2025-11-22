#include "eleve.h"
// #include <Imagine/Graphics.h>
#include <iostream>
#include <cassert>

// using namespace Imagine;
using namespace std;

Eleve::Eleve(string n) : name(n) {};

void Eleve::setGrade(int g) { grade = g; };

int Eleve::getGrade() const
{
    if (grade == -1)
    {
        cout << "No grade, error_value : ";
        return -1;
    }
    else
    {
        return grade;
    }
};

string Eleve::getName() const { return name; };

void afficher_classe(const vector<Eleve> &classe)
{
    cout << "Nouvelle classe de " << classe.size() << " eleves : " << endl;
    for (Eleve eleve : classe)
    {
        cout << "Nom : " << eleve.getName() << " | Note : ";
        cout << eleve.getGrade() << endl;
    };
    cout << endl;
}

void afficher_classe_ordre(const vector<Eleve> &classe, int ordre[], int taille, int n_comparaisons)
{
    for (int k = 0; k < taille; k++)
        cout << classe[ordre[k]].getName() << " (" << classe[ordre[k]].getGrade() << ")" << endl;
    cout << "Nombre de comparaisons pour ce tri : " << n_comparaisons << endl;
}