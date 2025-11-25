#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


const int NbEleve = 15;

class Eleve{
    std::string name;
    int note;
public:
    Eleve(std::string ch, int mark);
    std::string getName() const;
    void setName(std::string ch);
    int getNote() const;
    void setNote(int mark);
};

class CompareName{
    const std::vector<Eleve>* Eleves;
    int* ptr;
public:
    CompareName(const std::vector<Eleve>* e, int* compteur);
    bool operator()(int i, int j) const;
};

class CompareNote{
    const std::vector<Eleve>* Eleves;
    int* ptr;
public:
    CompareNote(const std::vector<Eleve>* e, int* compteur);
    bool operator()(int i, int j) const;
};

void display(int* tab, std::vector<Eleve>& e);
