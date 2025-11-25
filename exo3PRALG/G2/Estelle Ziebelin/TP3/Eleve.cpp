#include "Eleve.h"
#include <cstdlib>
#include <ctime>

Eleve :: Eleve (std::string str, int n) {
    nom = str ; note = n ;
}

Eleve::Eleve() {
    nom = "";
    note = 0;
}

std::string Eleve::get_nom() const {
    return nom;
}
int Eleve::get_note() const{
    return note;
}

void Eleve::change_note(int n) {
    note = n;
}

void Eleve:: print() const{
    std::cout << "Nom : " << nom << "  Note : " << note << std::endl ;
}


void random_init() {
    static bool deja_fait = false;
    if (!deja_fait) {
        srand(time(0));
        deja_fait = true;
    }
}

char random_lettre_min() {
    return 'a' + rand() % 26;
}


std::string random_nom() {
    random_init();

    int len = 1 + rand() % 10;
    std::string nom;

    nom += 'A' + rand() % 26;

    for (int i = 0; i < len; ++i)
        nom += random_lettre_min();

    return nom;
}


int random_note() {
    random_init();
    return rand() % 21;
}


Eleve random_eleve() {
    return Eleve(random_nom(), random_note());
}


std::vector<Eleve> random_class(int nb_eleves) {
    std::vector<Eleve> classe;
    for (int i = 0; i < nb_eleves; ++i)
        classe.push_back(random_eleve());
    return classe;
}

void afficher_classe(const std::vector<Eleve>& classe) {
    for (auto it = classe.cbegin(); it != classe.cend(); ++it)
        it->print();
}
