#pragma once
#include <string>
#include <vector>
using namespace std;


class Eleve {
public:
    string  Name ;
    int grade;
    Eleve();
};

class CompareNom{
public:
    int* ptr=nullptr;
    CompareNom(int* p) : ptr(p) {}
    bool operator () ( const Eleve & i ,  const Eleve & j) const {
        ++(*ptr);
        return i.Name< j.Name;
    }

};

class CompareNote{
public:
    int* ptr=nullptr;
    CompareNote(int* p): ptr(p){}
    bool operator () ( const Eleve & a ,  const Eleve & b) const {
        ++(*ptr);
        return a.grade >b.grade;

    }
};

