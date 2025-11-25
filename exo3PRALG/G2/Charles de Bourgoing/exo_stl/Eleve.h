#pragma once

#include <string>
#include <algorithm>
using namespace std;

class Eleve{
public:
    string nom;
    int note;
};

class CompareNote{
public:
    int* ptr;
    bool operator()(Eleve E1, Eleve E2) const {
        ++*ptr;
        return(E1.note>E2.note);
    }
    //~CompareNote(); pas besoin
    CompareNote(int& compteur);
};

class CompareNom{
public:
    int* ptr;
    bool operator()(Eleve E1, Eleve E2) const {
        ++*ptr;
        string nom1 = E1.nom;
        string nom2 = E2.nom;
        for(int i=0;i<min(nom1.length(),nom2.length());i++) {
            if(nom1[i]<nom2[i]) {
                return true;
            } else if(nom1[i]>nom2[i]) {
                return false;
            }
        }
        return true;
    }
    //~CompareNom();
    CompareNom(int& compteur);
};
