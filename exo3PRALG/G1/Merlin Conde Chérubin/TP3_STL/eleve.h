#pragma once

#include <cassert>

#include <iostream>
using namespace std;

// #include <Imagine/Graphics.h>
// using namespace Imagine;

class Eleve{
    string nom;
    int note;
public:
    Eleve(string name, int grade); //constructor

    Eleve(const Eleve& E); //copy constructor

    //definition of method for Eleve
    string getNom() const;
    int getNote() const;
};


Eleve randomEleve();

struct CompareNom{
    int* ptr = 0;
    bool operator()(const Eleve& A, const Eleve& B) {
        ++*ptr;
        return A.getNom()<B.getNom();
    };
};

struct CompareNote{
    int* ptr;
    bool operator()(const Eleve& A, const Eleve& B){
        ++*ptr;
        return A.getNote()>B.getNote();
    };
};

template <class T>
void printVector(const vector<T>& V){
    cout << "[";
    typename vector<T>::const_iterator it = V.begin();
    for(; it!=V.end(); ++it){
        cout << "(nom : " << it->getNom() << ", note : " << it->getNote() << "), ";
    }
    cout << "]" << endl;
}

