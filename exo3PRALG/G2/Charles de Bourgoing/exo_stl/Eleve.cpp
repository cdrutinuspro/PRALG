#pragma once


#include "Eleve.h"

/*CompareNom::~CompareNom() {
    delete ptr;
}*/
CompareNom::CompareNom(int& compteur){
    ptr = &compteur;
}

/*CompareNote::~CompareNote() {
    delete ptr;
}*/ // ne rien supprimer puisque les variables ne sont pas initialisées avec new, mais par référence :
CompareNote::CompareNote(int& compteur){
    ptr = &compteur;
}
