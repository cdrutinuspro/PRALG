#include "Eleve.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


int main() {
    srand((unsigned int) time(0));
    int mark;
    string name;
    vector<Eleve> classroom;
    classroom.reserve(10);
    for (int i=0; i < 10; i++){
        mark=rand()%21;
        name = randomName();
        classroom.emplace_back(name, mark);
    };
    int compteur=0;
    sort(classroom.begin(),classroom.end(),Comparenom(&compteur));
    cout << "\n" << "tri par nom" << "\n";
    affichage(classroom);
    cout << "\n" << "Compteur = " << compteur<<"\n";

    compteur=0;

    sort(classroom.begin(),classroom.end(),Comparenote(&compteur));
    cout << "\n" << "tri par note" << "\n";
    affichage(classroom);
    cout << "\n" << "Compteur = " << compteur<<"\n";

    return 0;
};
