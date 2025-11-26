#ifndef ELEVE_H
#define ELEVE_H

#include <string>

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
};


class CompareNom {
private:
    int* ptr_compteur;

public:
    CompareNom(int* ptr = nullptr) : ptr_compteur(ptr) {}

    bool operator()(const Eleve& e1, const Eleve& e2);
};


class CompareNote {
private:
    int* ptr_compteur;

public:
    CompareNote(int* ptr = nullptr) : ptr_compteur(ptr) {}

    bool operator()(const Eleve& e1, const Eleve& e2);
};

#endif // ELEVE_H

