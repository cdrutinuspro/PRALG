#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>


class Eleve {

private :

    std::string name;
    int note;

public :

    Eleve();
    Eleve(const std::string& nom, int note_eleve);

    int getNote() const;
    std::string getName() const;

    void setNote(int nouvelleNote);
    void setName(const std::string& nouveauNom);

    void afficher() const;

    static Eleve genererEleveAleatoire();





};

class CompareNom {


private:
    int* ptr;

public:
    CompareNom(int* counter);
    bool operator()(const Eleve& a, const Eleve& b) const;

};


class CompareNote {


private:
    int* ptr;


public:
    CompareNote(int* counter);
    bool operator()(const Eleve& a, const Eleve& b) const;

};

void afficherEleves(const std::vector<Eleve>& eleves);
std::vector<Eleve> genererVecteurElevesAleatoires();

