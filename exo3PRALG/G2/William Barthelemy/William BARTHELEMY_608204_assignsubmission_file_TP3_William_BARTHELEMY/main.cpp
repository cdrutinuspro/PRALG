#include "student.h"

using namespace std;

int main(){
    srand(time(nullptr));
    vector<Eleve> eleves = {};
    int compteur = 0;
    for(int i = 0; i < 20; i ++) {
        eleves.push_back(Eleve("0",0,true));
    }
    cout << "---- Non trié ----" <<endl;
    DisplayEleves(eleves);
    sort(eleves.begin(), eleves.end(), CompareNom(compteur));
    cout << "---- Trié par nom ----" << endl;
    DisplayEleves(eleves);
    cout << "Nombre de comparaisons pour le tri par nom : " << compteur << endl;
    compteur = 0;
    sort(eleves.begin(), eleves.end(), CompareNote(compteur));
    cout << "---- Trié par Note (Décroissant) ----" << endl;
    DisplayEleves(eleves);
    cout << "Nombre de comparaisons pour le tri par note : " << compteur << endl;
    return 0;
};