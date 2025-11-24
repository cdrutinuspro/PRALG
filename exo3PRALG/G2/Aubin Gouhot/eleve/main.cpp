// Aubin GOUHOT

#include <iostream>
#include <vector>
#include "eleve.h"
#include <stdlib.h>
using namespace std;

int main()
{
    srand( time( NULL ) );
    std::vector<Eleve> eleves;
    int n_eleves = rand()%100;
    for (int i=0; i<n_eleves; i++){
        int grade = rand()%20;
        int name_length = rand()%10 + 1;
        string name;
        char first_letter = rand()%('Z'-'a') + int('A');
        name+=first_letter;
        for (int j=0; j<name_length;j++){
            char c;
            c = rand()%('z'-'a') + int('a');
            name+=c;
        }
        Eleve eleve(name,grade);
        eleves.push_back(eleve);
    }

    cout <<"Comparaison par nom"<<endl;
    int compteur = 0;
    CompareEleve_nom cmp;
    cmp.ptr = &compteur;

    std::sort(eleves.begin(), eleves.end(),cmp);
    display(eleves);
    cout<<"Nombre de comparaison par nom : "<<compteur<<endl;

    cout <<"Comparaison par note"<<endl;
    int compteur_note = 0;
    CompareEleve_note cmp_note;
    cmp_note.ptr = &compteur_note;

    std::sort(eleves.begin(), eleves.end(),cmp_note);
    display(eleves);
    cout<<"Nombre de comparaison par note : "<<compteur_note<<endl;
    return 0;
}
