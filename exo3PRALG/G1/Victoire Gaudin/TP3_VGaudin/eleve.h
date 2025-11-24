#pragma once
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class Eleve
{
    string name;
    int note;
public:
    Eleve(string name0, int note0);
    string getname() const;
    int getnote() const;
    static int generernotealeatoire();
    static string generernomaleatoire();
    static void remplirvecteur(vector<Eleve>& classe, int nb_eleves);
    static void triervecteurnom(vector<Eleve>& classe, int* compteur);
    static void triervecteurnote(vector<Eleve>& classe, int* compteur);
    static void affichervecteur(const vector<Eleve>& classe);
};


class CompareNom{
    int* ptr;
public:
    CompareNom(int* ptr0);
    bool operator()(const Eleve e1, const Eleve e2);
};

class CompareNote{
    int* ptr;
public:
    CompareNote(int* ptr0);
    bool operator()(const Eleve e1, const Eleve e2);
};

