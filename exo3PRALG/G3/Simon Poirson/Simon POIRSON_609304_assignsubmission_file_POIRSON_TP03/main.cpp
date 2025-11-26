#include "eleve.h"
#include <algorithm>


int random_int_0_20() {
    return std::rand() % 21;
}

std::string random_name10() {
    std::string s;
    s.reserve(10);
    s.push_back(char('A' + std::rand() % 26));
    for (int i = 1; i < 10; ++i)
        s.push_back(char('a' + std::rand() % 26));
    return s;
}

void display(vector<eleve>& v) {
    for (vector<eleve>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it).nom << "  ";
    }
    cout << endl;
}

int main() {
    int compteur =0;
    std::vector<eleve> t;
    for (int i = 0; i<25; i++) {
        t.push_back(eleve(random_name10(),random_int_0_20()));
    }
    cout << "Vecteur de taille 25 engendré." << endl;
    CompareNom comp1(&compteur);
    std::sort(t.begin(),t.end(),comp1);
    cout << "Ordre alphabétique :" << endl;
    display(t);
    int et1 = compteur;
    cout << "Nombre de comparaisons effectuées : " << et1 << "  Nombre total de comparaisons effetuées : " << compteur << endl;
    CompareNote comp2(&compteur);
    std::sort(t.begin(),t.end(),comp2);
    cout << "Classement par note :" << endl;
    display(t);
    int et2 = (compteur - et1);
    cout << "Nombre de comparaisons effectuées : " << et2 << "  Nombre total de comparaisons effetuées : " << compteur << endl;
    return 0;
}