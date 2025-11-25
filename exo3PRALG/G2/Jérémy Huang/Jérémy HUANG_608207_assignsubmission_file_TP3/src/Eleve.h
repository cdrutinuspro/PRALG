#pragma once
#include <string>
#include <vector>

class Eleve{
    std::string nom;
    int note;
public:
    Eleve(std::string nom, int note);
    std::string get_nom() const { return nom; };
    int get_note() const { return note; };
};

class CompareNom{
    int* ptr;
public:
    CompareNom() {ptr = new int(0);};
    bool operator()(const Eleve& e1, const Eleve& e2);
    int get_ptr() { return *ptr; };
};

class CompareNote{
    int* ptr;
public:
    CompareNote() {ptr = new int(0);};
    bool operator()(const Eleve& e1, const Eleve& e2);
    int get_ptr() { return *ptr; };
};

CompareNom sort_by_nom(std::vector<Eleve>& liste_eleve);
CompareNote sort_by_note(std::vector<Eleve>& liste_eleve);