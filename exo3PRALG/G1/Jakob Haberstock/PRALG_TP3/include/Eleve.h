#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


class Eleve {
    string name;
    int note;
public:
    Eleve(string, int);
    Eleve(const Eleve&);
    ~Eleve();
    string getName() const;
    int getNote() const;
    void setName(string);
    void setNote(int);
    string getStringRep() const;
};

// foncteurs:
class CompareName {
public: 
    int* ptr;
    CompareName();
    ~CompareName();
    bool operator()(Eleve, Eleve) const;
    int getIntPtrValue() const;
};
class CompareNote {
public: 
    int* ptr;
    CompareNote();
    ~CompareNote();
    bool operator()(Eleve, Eleve) const;
    int getIntPtrValue() const;
};