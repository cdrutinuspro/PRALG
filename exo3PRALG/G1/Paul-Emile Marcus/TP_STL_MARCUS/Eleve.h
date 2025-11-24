#pragma once
#include <string>
using namespace std;

class Eleve{
    string nom;
    int note;
public:
    Eleve(string a, int b);
    int getGrade() const;
    string getName() const;
    void display() const;
};
