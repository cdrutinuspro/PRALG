// #include <QCoreApplication>
#include "Eleve.h"

const int N = 10;

int main(int argc, char *argv[])
{
    vector<Eleve> eleves;
    for(int i = 0; i<N; i++){
        Eleve e = random_eleve();
        eleves.push_back(e);
    }
    std::cout << "=== Liste des eleves ===" << endl;
    for (int i = 0; i < eleves.size(); ++i) {
        eleves[i].afficher();
    }
    cout<<endl;

    // Tri alphabétique
    int compteurNom = 0;
    CompareNom cmpNom(&compteurNom);
    std::sort(eleves.begin(), eleves.end(), cmpNom);

    std::cout << "\n=== Tri par nom (alphabetique) ===\n";
    for (int i = 0; i < eleves.size(); ++i) {
        eleves[i].afficher();
    }
    std::cout << "Nombre de comparaisons : " << compteurNom << "\n";

    // Tri par note décroissante
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    std::sort(eleves.begin(), eleves.end(), cmpNote);

    std::cout << "\n=== Tri par note decroissante ===\n";
    for (int i = 0; i < eleves.size(); ++i) {
        eleves[i].afficher();
    }
    std::cout << "Nombre de comparaisons : " << compteurNote << "\n";

    return 0;
}
