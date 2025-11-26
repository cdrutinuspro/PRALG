// #include "mainwindow.h"
// #include <QApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Eleve.h"
#include "Comparateurs.h"

using namespace std ;

string genererNom() {
    int taille = rand() % 10 + 1;
    string nom = "";
    char c = 'A' + rand() % 26;
    nom += c;
    for (int i = 0; i < taille; i++) {
        char min = 'a' + rand() % 26;
        nom += min;
    }
    return nom;
}

int genererNote() {
    return rand() % 21;
}

void afficher(const vector<Eleve>& liste) {
    for (unsigned int i = 0; i < liste.size(); i++) {
        cout << liste[i].getNom() << " - " << liste[i].getNote() << endl;
    }
}

int main() {
    srand(time(0));

    vector<Eleve> eleves;
    for (int i = 0; i < 15; i++) {
        string nom = genererNom();
        int note = genererNote();
        Eleve e(nom, note);
        eleves.push_back(e);
    }

    int compteur = 0;
    CompareNom cmpNom(&compteur);
    CompareNote cmpNote(&compteur);

    cout << "Tri alphabetique :" << endl;
    compteur = 0;
    sort(eleves.begin(), eleves.end(), cmpNom);
    afficher(eleves);
    cout << "Nombre de comparaisons : " << compteur << endl << endl;

    cout << "Tri par note decroissante :" << endl;
    compteur = 0;
    sort(eleves.begin(), eleves.end(), cmpNote);
    afficher(eleves);
    cout << "Nombre de comparaisons : " << compteur << endl;

    return 0;
}
