#include "eleve.h"

Eleve::Eleve(const string &last_name)
{
    nom = last_name;
    notes = 0;
}

void Eleve::ajouterNote(float grade)
{
    notes = grade;
}

int Eleve::getNotes() const
{
    return notes;
}

string Eleve::getNom() const
{
    return nom;
}

//
bool CompareNom::operator()(const Eleve &e1, const Eleve &e2) const
{
    (*c_N)++;
    return e1.getNom() < e2.getNom();
}
//
bool CompareNotes::operator()(const Eleve &e1, const Eleve &e2) const
{
    (*c_G)++;
    return e1.getNotes() < e2.getNotes();
}