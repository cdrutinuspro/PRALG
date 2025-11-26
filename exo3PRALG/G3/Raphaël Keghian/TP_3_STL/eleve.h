#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Eleve
{
    string name; int grade;
public:
    Eleve(string n, int g);
    string& get_name();
    int& get_grade();

};

class CompareNote{
    int* ptr;
public:
    int get_compteur(){return *ptr;}
    CompareNote(int* cmp){ptr = cmp;}
    bool operator()(Eleve e1, Eleve e2) const {++*ptr; return e1.get_grade()>e2.get_grade();}
};

class CompareNom{
    int* ptr;
public:
    int get_compteur(){return *ptr;}
    CompareNom(int* cmp){ptr = cmp;}
    bool operator()(Eleve e1, Eleve e2) const {return e1.get_name() < e2.get_name();}
};
