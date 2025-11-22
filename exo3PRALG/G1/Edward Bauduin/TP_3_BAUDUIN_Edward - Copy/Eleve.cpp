#include "Eleve.h"

//Declaration of the empty constructor
Eleve::Eleve() {
    nom = "";
    note = 0;
}

//Declaration of the constructor
Eleve::Eleve(string nom_, int note_) {
    note = note_;
    nom = nom_;

}

//Declaration of accessor methods
const string& Eleve::name() const{
    return nom;
}

const int& Eleve::grade() const{
    return note;
}

//Declaration of the CompareNom class
bool CompareNom::operator()(const Eleve& el_1, const Eleve& el_2) const{
    if (ptr) ++(*ptr);
    return el_1.name() < el_2.name();
}

//Declaration of the CompareNote class
bool CompareNote::operator()(const Eleve& el_1, const Eleve& el_2) const{
    if (ptr) ++(*ptr);
    return el_2.grade() < el_1.grade();
}

