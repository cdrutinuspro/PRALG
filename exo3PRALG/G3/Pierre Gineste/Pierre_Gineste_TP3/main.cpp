#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "eleve.h"
#include "Comparators.h"
#include <math.h>

using namespace std;

void afficherEleves(const vector<Eleve>& eleves, const string& titre = "") {
    if (!titre.empty()) {
        cout << "\n" << titre << endl;
        cout << string(titre.length(), '=') << endl;
    }

    for (vector<Eleve>::const_iterator it = eleves.begin();
         it != eleves.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const int NB_ELEVES = 15;
    vector<Eleve> eleves;

    cout << "\nGénération de " << NB_ELEVES << " élèves aléatoires" << endl;

    for (int i = 0; i < NB_ELEVES; i++) {
        eleves.push_back(Eleve::genererAleatoire());
    }

    afficherEleves(eleves, "Liste initiale (ordre aléatoire)");

    cout << "\n\n TRI ALPHABÉTIQUE PAR NOM " << endl;

    int compteur_nom = 0;

    CompareNom cmp_nom(&compteur_nom);

    vector<Eleve> eleves_par_nom = eleves;

    sort(eleves_par_nom.begin(), eleves_par_nom.end(), cmp_nom);

    afficherEleves(eleves_par_nom, "Liste triée par nom (ordre alphabétique)");

    cout << "\nNombre de comparaisons effectuées : " << compteur_nom << endl;

    cout << "\n\n--- TRI PAR NOTE DÉCROISSANTE ---" << endl;

    int compteur_note = 0;

    CompareNote cmp_note(&compteur_note);

    vector<Eleve> eleves_par_note = eleves;

    sort(eleves_par_note.begin(), eleves_par_note.end(), cmp_note);

    afficherEleves(eleves_par_note, "Liste triée par note (ordre décroissant)");

    cout << "\nNombre de comparaisons effectuées : " << compteur_note << endl;

    cout << "Nombre d'élèves : " << NB_ELEVES << endl;
    cout << "Comparaisons (tri par nom)  : " << compteur_nom << endl;
    cout << "Comparaisons (tri par note) : " << compteur_note << endl;

    // Complexité théorique : O(n log n)
    double complexite_theorique = NB_ELEVES * log2(NB_ELEVES);
    cout << "\nComplexité théorique O(n log n) : ~"
         << static_cast<int>(complexite_theorique) << " comparaisons" << endl;

    return 0;
}
