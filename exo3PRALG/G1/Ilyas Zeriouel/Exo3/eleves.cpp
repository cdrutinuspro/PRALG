#include "eleves.h"

Eleve::Eleve(std::string name, int mark) {
    nom = name;
    note = mark;
}

int Eleve::getMark() const {
    return note;
}

std::string Eleve::getName() const {
    return nom;
}

void Eleve::setData(std::string name, int mark) {
    nom = name;
    note = mark;
}

void print(const std::vector<Eleve>& V) {
    std::vector<Eleve>::const_iterator it = V.begin();
    for (; it != V.end(); ++it)
        std::cout << it->getName() << " : " << it->getMark() << '\n';
}


void decreasing_names(std::vector<Eleve>& eleves, int& compteur) {
    std::sort(eleves.begin(), eleves.end(), CompareNoms(&compteur));
    print(eleves);
}


void decreasing_marks(std::vector<Eleve>& eleves, int& compteur) {
    std::sort(eleves.begin(), eleves.end(), CompareNotes(&compteur));
    print(eleves);
}

CompareNotes::CompareNotes(int* p) {
    ptr = p;
}

CompareNoms::CompareNoms(int* p) {
    ptr = p;
}
