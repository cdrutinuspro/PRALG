#pragma once
#include <string>
using namespace std;

//Definition of the class Eleve
class Eleve {
    string nom;
    int note;
public:
    //Empty constructor (not exactly necessary in this case because we directly assign values to nom and note through uniform distribution density)
    Eleve();
    //Constructor
    Eleve(string nom_, int note_);
    //Accessors for name and grade of the student
    const string& name() const;
    const int& grade() const;
};

//Definition of the class CompareNom
class CompareNom{
public:
    int* ptr = nullptr;
    bool operator()(const Eleve& el_1, const Eleve& el_2) const;

};

//Definiton of the class CompareNote
class CompareNote{
public:
    int* ptr = nullptr;
    bool operator()(const Eleve& el_1, const Eleve& el_2) const;
};
