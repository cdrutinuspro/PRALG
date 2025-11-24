#include "eleve.h"
#include <vector>
using namespace std;
//author : Merlin Conde Chérubin


int main(){
    int compteurNote = 0;
    CompareNote cmpNote;
    int compteurNom = 0;
    CompareNom cmpNom;
    cmpNote.ptr = &compteurNote;
    cmpNom.ptr = &compteurNom;
    vector<Eleve> liste_eleves;
    for (int i=0; i<20; i++){
        liste_eleves.push_back(randomEleve());
    }
    //tri par nom
    sort(liste_eleves.begin(), liste_eleves.end(), cmpNom);
    cout << "Tri par nom :" << endl;
    printVector(liste_eleves);
    cout << "Nombre de comparaison tri par Nom : " << compteurNom << endl;

    //tri par note
    sort(liste_eleves.begin(), liste_eleves.end(), cmpNote);
    cout << "Tri par note :" << endl;
    printVector(liste_eleves);
    cout << "Nombre de comparaison tri par Note : " << compteurNote << endl;


    return 0;
}
