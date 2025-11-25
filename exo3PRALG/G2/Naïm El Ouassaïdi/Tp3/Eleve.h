#pragma once
#include<iostream>
#include <vector>
using namespace std;

class Eleve{
public:
    string name;
    int mark;
    Eleve();
    Eleve(string noun, int k);
    Eleve(const Eleve& student);
};

class CompareNom{
public:
    int* ptr;
    CompareNom(int* p=nullptr){ptr=p;}
    bool operator()(Eleve a ,Eleve b) const{
        ++*ptr;
        return a.name<b.name;
    }
};

class CompareNote{
public:
    int* ptr;
    CompareNote(int* p=nullptr){ptr=p;}
    bool operator()(Eleve a, Eleve b) const{
        ++*ptr;
        return a.mark<b.mark;
    }
};
