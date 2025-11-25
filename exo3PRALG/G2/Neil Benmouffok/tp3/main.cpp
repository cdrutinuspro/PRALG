// #include <Imagine/Graphics.h>
#include "matrice.h"
#include <iostream>
#include <ctime>

using namespace Imagine;
using namespace std;


void remplirAleatoire(Matrice& M) {
    for (int i = 0; i < M.lignes(); i++) {
        for (int j = 0; j < M.colonnes(); j++) {
            M(i, j) = rand() % 10; // on remplit avec des entiers pour simplifier et vérifier les calculs rapidement ça marche aussi avec des réels
        }
    }
}

int main() {
    srand(time(0)); // initialisation aléatoire

    cout << "=== Début du programme ===" << endl;

        for (int tour = 1; tour <= 5; tour++) {
        cout << "\n--- Tour " << tour << " ---" << endl;

        // Créer deux matrices aléatoires avec tailles compatibles (petites tailles pour vérifier les calculs rapidement)
        int m = 2 + rand() % 3;  // entre 2 et 4 lignes
        int n = 2 + rand() % 3;  // entre 2 et 4 colonnes
        int p = 2 + rand() % 3;  // entre 2 et 4 colonnes pour la seconde

        Matrice A(m, n);
        Matrice B(n, p); // nb lignes de B = nb colonnes de A
        remplirAleatoire(A);
        remplirAleatoire(B);

        cout << "Matrice A (" << m << "x" << n << ") :" << endl;
        A.afficher();

        cout << "Matrice B (" << n << "x" << p << ") :" << endl;
        B.afficher();

        // Copie de A pour tester la copie
        Matrice A_copie = A;
        cout << "Copie de A :" << endl;
        A_copie.afficher();

        // Multiplication
        Matrice C = A * B;
        cout << "Résultat C = A * B :" << endl;
                                              C.afficher();
    }

    cout << "\n=== Fin du programme ===" << endl;
    return 0;
}
