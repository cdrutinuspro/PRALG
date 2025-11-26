#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <iostream>

class Eleve {
private:
    std::string nom;
    int note;

public:
    Eleve();
    Eleve(const std::string& nom, int note);


    std::string getNom() const;
    int getNote() const;

    void setNom(const std::string& nom);
    void setNote(int note);

    void afficher() const;

    static Eleve genererAleatoire();
};

std::ostream& operator<<(std::ostream& os, const Eleve& eleve);

#endif
