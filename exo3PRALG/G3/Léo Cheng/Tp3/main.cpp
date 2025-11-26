// Imagine++ project
// Project:  Tp3
// Student(s): CHENG Léo

#include "eleve.h"
#include <algorithm>

void affichage(vector<Eleve> v){
    vector<Eleve>::iterator it = v.begin();
    for(; it!=v.end(); it++){
        cout << *it;
    }
}

int main() {
    std::vector<Eleve> v;
    for(int i = 0; i<20; i++){
        v.push_back(Eleve());
    }
    cout << "Liste par defaut" << endl;
    affichage(v);

    int compteur = 0;
    CompareNom cmp;
    cmp.ptr = &compteur;
    cout << endl << "Liste triee par nom" << endl;
    std::sort(v.begin(), v.end(), cmp);
    affichage(v);
    cout << endl << "compteur : " << compteur << endl;

    int compteur2 = 0;
    CompareNote cmp2;
    cmp2.ptr = &compteur2;
    cout << endl << "Liste triee par note" << endl;
    std::sort(v.begin(), v.end(), cmp2);
    affichage(v);
    cout << endl << "compteur : " << compteur2 << endl;
}
