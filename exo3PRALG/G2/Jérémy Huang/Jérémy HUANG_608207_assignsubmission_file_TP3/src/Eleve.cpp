#include "Eleve.h"
#include <iostream>
#include <algorithm>
#include <vector>

Eleve::Eleve(std::string nom_, int note_){
    nom = nom_;
    note = note_;
}

bool CompareNom::operator()(const Eleve& e1, const Eleve& e2){
    ++*ptr;
    return e1.get_nom() < e2.get_nom();
}

bool CompareNote::operator()(const Eleve& e1, const Eleve& e2){
    ++*ptr;
    return e1.get_note() > e2.get_note();
}

CompareNom sort_by_nom(std::vector<Eleve>& liste_eleve){
    CompareNom c;
    std::sort(liste_eleve.begin(), liste_eleve.end(), c);
    std::cout << "Liste des élèves triée par nom : " << std::endl;
    for (const Eleve& e : liste_eleve){
        std::cout << e.get_nom() << " : " << e.get_note() << std::endl;
    }
    return c;
}

CompareNote sort_by_note(std::vector<Eleve>& liste_eleve){
    CompareNote c;
    std::sort(liste_eleve.begin(), liste_eleve.end(), c);
    std::cout << "Liste des élèves triée par note : " << std::endl;
    for (const Eleve& e : liste_eleve){
        std::cout << e.get_nom() << " : " << e.get_note() << std::endl;
    }
    return c;
}
