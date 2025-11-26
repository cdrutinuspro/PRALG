#pragma once
#include <string>

class Eleve {
private:
    std::string nom;
    int note;

public:
    Eleve();
    Eleve(std::string n, int no);

    std::string getNom() const;
    int getNote() const;

    void setNom(std::string n);
    void setNote(int n);
};
