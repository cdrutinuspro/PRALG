#include <iostream>
#include "Eleve.h"
#include <random>
#include <vector>
#include <algorithm>
#include "CompareNom.h"
#include "CompareNote.h"
using namespace std;

//Paul-Emile Marcus

int main()
{
    srand(0);
    vector<Eleve> eleves;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int note;
    string nom;
    for(int i = 0; i<30; i++){
        note = rand()%21;
        int longueur_nom = rand()%10 + 1;
        nom = "";
        nom += alphabet[rand()%26];
        for(int j = 1; j<longueur_nom;j++){
            nom += alphabet[26+rand()%26];
        }
        Eleve e(nom,note);
        eleves.push_back(e);
    }

    int compteur = 0;

    cout<<"Tri croissant par noms :"<<"\n"<<endl;
    sort (eleves.begin(),eleves.end(),CompareNom(&compteur));
    for(int i = 0; i<eleves.size() ; i++){
        eleves[i].display();
    }
    cout<<"\n"<<compteur<<" comparaisons effectuées"<<"\n"<<"\n"<<"Tri croissant par notes :"<<"\n"<<endl;

    compteur = 0;
    sort (eleves.begin(),eleves.end(),CompareNote(&compteur));
    for(int i = 0; i<eleves.size() ; i++){
        eleves[i].display();
    }
    cout<<"\n"<<compteur<<" comparaisons effectuées"<<endl;


    return 0;
}
