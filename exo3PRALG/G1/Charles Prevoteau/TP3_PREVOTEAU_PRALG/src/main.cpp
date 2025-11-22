#include "eleve.h"
// #include <Imagine/Graphics.h>
#include <iostream>
#include <numeric>

// using namespace Imagine;
using namespace std;

int main()
{

    srand(time(0));
    int n_eleves = 30;

    // Question 2
    vector<Eleve> classe;
    for (int i = 0; i < n_eleves; i++)
    {
        string nom;
        nom += char('A' + rand() % 26);
        for (int j = 0; j < rand() % 10; j++)
        {
            nom += char('a' + rand() % 26);
        };
        Eleve eleve(nom);
        eleve.setGrade(rand() % 21);
        classe.push_back(eleve);
    }
    afficher_classe(classe);

    // Question 3

    // Comparaison par ordre alphabétique
    int compteur = 0;
    NameComparator name_comparateur = NameComparator(classe);
    name_comparateur.ptr = &compteur;
    int ordre_alpha[n_eleves];
    iota(ordre_alpha, ordre_alpha + n_eleves, 0);
    sort(ordre_alpha, ordre_alpha + n_eleves, name_comparateur);
    cout << "Tri par ordre alphabetique : " << endl;
    afficher_classe_ordre(classe, ordre_alpha, n_eleves, compteur);

    // Comparaison par ordre de note
    compteur = 0;
    GradeComparator grade_comparateur = GradeComparator(classe);
    grade_comparateur.ptr = &compteur;
    int ordre_note[n_eleves];
    iota(ordre_note, ordre_note + n_eleves, 0);
    sort(ordre_note, ordre_note + n_eleves, grade_comparateur);
    cout << "Tri par ordre decroissant de notes : " << endl;
    afficher_classe_ordre(classe, ordre_note, n_eleves, compteur);

    return 0;
}