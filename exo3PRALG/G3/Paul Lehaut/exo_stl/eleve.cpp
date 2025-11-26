#include "eleve.h"

// Constructeur -----------------------------------------------------

Eleve :: Eleve(int note_propose, std :: string nom_propose)
{
    if (nom_propose.empty())
        throw std :: underflow_error("Le nom est vide");
    else if (not std::isupper(static_cast<unsigned char>(nom_propose[0])))
        throw std :: underflow_error("La première lettre n'est pas une majuscule.");
    nom = nom_propose;
    if (0>note_propose || 20<note_propose)
        throw std :: out_of_range("La note n'est pas entre 0 et 20.");
    note=note_propose;
}

// Méthodes --------------------------------------------------------

void Eleve :: display()
{
    std :: pair<int, std :: string> p(note, nom);
    std :: cout << "L'eleve " << p.second << " a obtenu la note " << p.first << "." << std :: endl;
}

std::string Eleve :: getNom()
{
    return nom;
}

int Eleve :: getNote()
{
    return note;
}

// Foncteurs -------------------------------------------------------

CompareNom :: CompareNom(int* compteur): ptr(compteur) {}

CompareNote :: CompareNote(int* compteur): ptr(compteur) {}

bool CompareNom :: operator()(Eleve eleve1, Eleve eleve2)
{ 
    ++*ptr;
    return eleve1.getNom()>eleve2.getNom();
}

bool CompareNote :: operator()(Eleve eleve1, Eleve eleve2)
{ 
    ++*ptr;
    return eleve1.getNote()>eleve2.getNote();
}
