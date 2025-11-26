#pragma once
#include <vector>
#include <iostream>
using namespace std;

// question 1
class Eleve{
    string name;
    int mark;
public:
    void set(string name0, int mark0) {name=name0; mark=mark0;}
    void get(string& name0, int& mark0) const {name0=name; mark0=mark;}
    void get_name(string& name0) const {name0=name;}
    void get_mark(int& mark0) const {mark0=mark;}
};

// question 3
class CompareNom{
public :
    int* ptr = nullptr; // question 5
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const;
};

class CompareNote{
public :
    int* ptr = nullptr; // question 5
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const;
};

// question 4
ostream& operator<<(ostream& str, const vector<Eleve>& eleves_vector);

