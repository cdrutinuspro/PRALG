#pragma once

#include <iostream>
using namespace std;

// #include <Imagine/Graphics.h>
// using namespace Imagine;

#include <vector>


class Eleve{
    string name;
    int grade;
public:
    Eleve(string nm, int grd);
    Eleve(const Eleve& elv);
    void operator= (const Eleve& elv);

    int getGrade() {return grade;}
    string getName() {return name;}
    void affiche();
};

class CompareNote {
    int* ptr;
public:
    CompareNote(int* p) {ptr = p;}
    bool operator()(Eleve A, Eleve B) const {
        ++*ptr;
        return A.getGrade() > B.getGrade();
    }
};

class CompareNom{
    int* ptr;
public:
    CompareNom(int* p) {ptr = p;}
    bool operator()(Eleve A, Eleve B) const {
        ++*ptr;
        return A.getName() < B.getName();
    }
};