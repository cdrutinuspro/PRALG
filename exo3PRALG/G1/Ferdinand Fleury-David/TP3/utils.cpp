#include "util.h"
#include <cstdlib>
#include <ctime>
#include "eleve.h"
#include <vector>

string nomAleatoire(){
    int longueur= 1 + rand()%10;
    string nom;
    nom='A' +rand()%26;
    for(int i = 0; i< longueur; ++i)
        nom+= 'a' + rand()%26;
    return nom;
}

vector<Eleve> genererEleves(int n) {
    vector<Eleve> liste;
    for (int i = 0; i<n; ++i){
        string nom=nomAleatoire();
        float moyenne=rand()%21;
        liste.push_back(Eleve(nom, moyenne));
    }
    return liste;
}

