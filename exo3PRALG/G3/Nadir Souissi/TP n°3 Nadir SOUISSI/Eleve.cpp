#include "Eleve.h"
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>  // rand(), srand()


Eleve::Eleve() {
    name = "";
    grade = 0;
}

Eleve::Eleve(const string& n, int g) {
    name = n;
    grade = g;
}

string Eleve::getName() const {
    return name;
}

int Eleve::getGrade() const {
    return grade;
}

void Eleve::setName(const string& n) {
    name = n;
}

void Eleve::setGrade(int g) {
    grade = g;
}

void Eleve::afficher() const {
    cout << "Nom: " << name << ", Note: " << grade << endl;
}

Eleve::~Eleve() {
    
}


string randomName() {
    int length = 1 + rand() % 10;  // longueur entre 1 et 10
    string name;
    name += 'A' + rand() % 26;     // première lettre majuscule + le rand % 26 pour avoir une lettre entre A et Z

    for (int i = 0; i < length; ++i)
        name += 'a' + rand() % 26; // lettres minuscules

    return name;
}


vector<Eleve> listofStudents(int n) {
    vector<Eleve> v;
    for (int i = 0; i < n; ++i) {
        string name = randomName();
        int grade = rand() % 21; // entre 0 et 20 inclus
        v.push_back(Eleve(name, grade));
    }
    return v;
}

void affichage(const vector<Eleve>& classe) {
    for (auto it = classe.begin(); it != classe.end(); ++it) {
        it->afficher();
    }
}