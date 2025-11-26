#include "eleve.h"
#include <iostream>
using namespace std;

void afficher(const vector<Eleve> &eleves, string titre)
{
    cout << titre << endl;
    for (const Eleve &eleve : eleves)
    {
        cout << "Nom: " << eleve.getNom() << ", Note: " << eleve.getNotes() << endl;
    }
};

void create_random_list_eleve(vector<Eleve> &eleves, int n)
{
    string CAPS_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
    {
        string new_name = "";
        new_name += CAPS_alphabet[rand() % CAPS_alphabet.size()];
        int length_name = rand() % 10 + 1; //+1 pour au moins une lettre
        for (int j = 0; j < length_name; j++)
        {
            new_name += lower_alphabet[rand() % lower_alphabet.size()];
        }
        eleves.push_back(Eleve(new_name));
        eleves[i].ajouterNote(rand() % 21);
    }
}

int main()
{
    int N = 10;
    vector<Eleve> eleves;
    create_random_list_eleve(eleves, N);
    //
    int compteur_N = 0;
    CompareNom cmp_N;
    cmp_N.c_N = &compteur_N;
    sort(eleves.begin(), eleves.end(), cmp_N);
    afficher(eleves, "Eleves tries par nom:");
    cout << "Nombre de comparaison par noms : " << compteur_N << endl;
    //
    int compteur_G = 0;
    CompareNotes cmp_G;
    cmp_G.c_G = &compteur_G;
    sort(eleves.begin(), eleves.end(), cmp_G);
    afficher(eleves, "Eleves tries par notes:");
    cout << "Nombre de comparaison par notes : " << compteur_G << endl;
    return 0;
}