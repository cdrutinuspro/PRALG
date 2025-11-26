#include "eleve.h"



eleve::eleve(std::string NOM, int NOTE) {
    nom=NOM;
    note=NOTE;
}


CompareNom::CompareNom(int* compt) {
    ptr = compt;
}

bool CompareNom::operator()(const eleve& a, const eleve& b) {
    (*ptr)++;
    return a.nom<b.nom;
}

CompareNote::CompareNote(int* compt) {
    ptr = compt;
}

bool CompareNote::operator()(const eleve& a, const eleve& b) {
    (*ptr)++;
    return a.note>b.note;
}