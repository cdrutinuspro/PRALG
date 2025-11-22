#include <iostream>
#include <vector>
#include <algorithm>
#include "eleve.h"
#include "utils.h"
#include "foncteur.h"
using namespace std;

int main() {
    srand(time(nullptr));
    vector<Eleve> classe = genererEleves(10);

    cout << "---- Liste initiale ----\n";
    for (const auto& e : classe)
        cout << e.getNom() << " : " << e.getMoyenne() << endl;

    // Tri par nom
    int cmpNom = 0;
    CompareNom compNom(&cmpNom);
    sort(classe.begin(), classe.end(), compNom);

    cout << "\n---- Tri par nom ----\n";
    for (const auto& e : classe)
        cout << e.getNom() << " : " << e.getMoyenne() << endl;
    cout << "Comparaisons effectuées : " << cmpNom << endl;

    // Tri par note
    int cmpNote = 0;
    CompareNote compNote(&cmpNote);
    sort(classe.begin(), classe.end(), compNote);

    cout << "\n---- Tri par note décroissante ----\n";
    for (const auto& e : classe)
        cout << e.getNom() << " : " << e.getMoyenne() << endl;
    cout << "Comparaisons effectuées : " << cmpNote << endl;

    return 0;
}
