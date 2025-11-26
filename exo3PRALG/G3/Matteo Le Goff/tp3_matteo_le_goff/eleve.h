#ifndef ELEVE_H
#define ELEVE_H
#include <string>
#include <vector>

class Eleve
{
private:
    int note;
    std::string nom;
public:
    Eleve(std::string nom, int note);
    int getNote() const;
    std::string getNom() const;
};

class CompareNote
{
public:
    CompareNote() {}
    int* ptr;
    bool operator()(Eleve eleve1, Eleve eleve2) {
        ++*ptr;
        return eleve1.getNote() < eleve2.getNote();}
};

class CompareNom
{
public:
    CompareNom() {}
    int* ptr;
    bool operator()(Eleve eleve1, Eleve eleve2) {
        ++*ptr;
        return eleve1.getNom() < eleve2.getNom();
    }
};

void afficherClasse(const std::vector<Eleve>& classe);

#endif // ELEVE_H
