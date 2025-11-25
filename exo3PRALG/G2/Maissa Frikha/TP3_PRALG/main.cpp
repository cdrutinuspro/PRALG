#include <iostream>
#include <algorithm>
#include "eleve.h"
using namespace std;

int main()
{
    vector<Eleve> vec1 ;
    int taille = rand()%100 + 1 ;
    for(int i= 0; i < taille ; i++){
        int note = rand()%(21);
        string name;
        char premiereLettre = 'A' + rand() % 26;
        name = premiereLettre;
        int longueur = rand() % 10 + 1;
        for (int j = 0; j < longueur; j++) {
            char lettre = 'a' + rand() % 26;
            name += lettre;
        }
        Eleve eleve = Eleve(name, note);
        vec1.push_back(eleve);
    }
     vector<Eleve> vec = vec1;
    std :: cout << "Avant tri :" << std :: endl;
    afficherEleves(vec);

    int compteurName = 0;
    CompareName cmpName(&compteurName);
    cout << "\nTri par Nom :" << endl;
    sort(vec.begin(), vec.end(), CompareName());
    afficherEleves(vec);
    cout << "Nombre de comparaisons par nom : " << compteurName << endl;

    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    cout << "\nTri par note :" << endl;
    sort(vec.begin(), vec.end(), CompareNote());
    afficherEleves(vec);
    cout << "Nombre de comparaisons par Note : " << compteurNote << endl;


    return 0;
}
