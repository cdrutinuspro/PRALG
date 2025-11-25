#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Eleve.h"

void affichage_classement_note(vector<Eleve> eleves,int& compteur){
    string espaces[10];
    espaces[0] = "";
    for(int i=1;i<10;i++) {
        espaces[i]=espaces[i-1]+" ";
    }

    cout << "classement général des élèves par note : "<<endl;

    CompareNote cmp(compteur);
    std::sort(eleves.begin(),eleves.end(),cmp);
    for(int i=0;i<eleves.size();i++) {
        cout << i+1 << "] " << eleves[i].nom << espaces[10-eleves[i].nom.length()] << " note : " << eleves[i].note << endl;
    }
}

void affichage_alphabetique(vector<Eleve> eleves, int& compteur){
    cout << "liste des élèves par ordre alphabétique : " << endl;
    CompareNom cmp(compteur);
    std::sort(eleves.begin(),eleves.end(),cmp);
    for(auto Eleve: eleves) {
        cout << Eleve.nom << endl;
    }
}

int main()
{
    cout << "Exercice STL !" << endl;

    char alphabet[26];
    char alphabetCap[26];


    for (int ch = 'a'; ch <= 'z'; ch++) {
        alphabet[ch-'a'] = ch;
        alphabetCap[ch-'a'] = ch+'A'-'a';
    }


    srand(0);
    int nbEleves = rand()%10+10;
    cout << "nb élèves : "<<nbEleves<<endl;
    vector<Eleve> eleves;
    for(int i=0;i<nbEleves;i++){
        Eleve eleve;
        eleve.note = rand()%20;
        eleve.nom = alphabetCap[rand()%26];
        int tailleNom = rand()%10;
        for(int j=0;j<tailleNom;j++){
            eleve.nom = eleve.nom +alphabet[rand()%26];
        }
        cout << "nom : " << eleve.nom << ".     note : "<< eleve.note << endl;
        eleves.push_back(eleve);
    }

    int compteur = 0;

    affichage_classement_note(eleves,compteur);
    cout << "compteur : "<< compteur << endl;
    compteur=0;
    affichage_alphabetique(eleves,compteur);
    cout << "compteur : "<< compteur << endl;

    return 0;
}
