#include "Eleve.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Eleve::Eleve(const string& n, int no) : nom(n), note(no) {}

string Eleve::getNom() const { return nom; }
int Eleve::getNote() const { return note; }

void Eleve::afficher() const {
    cout << nom << " (" << note << ")" << endl;
}

bool CompareNom::operator()(const Eleve& a, const Eleve& b) const {
    if (ptr) ++(*ptr);
    return a.getNom() < b.getNom();
}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const {
    if (ptr) ++(*ptr);
    return a.getNote() > b.getNote();
}


Eleve genererEleveAleatoire() {
    int note = rand() % 21;

    int len = 1 + rand() % 10;
    string nom;
    nom += char('A' + rand() % 26);
    for (int i = 0; i < len; ++i)
        nom += char('a' + rand() % 26);

    return Eleve(nom, note);
}

void afficherVector(const vector<Eleve>& v) {
    for (const auto& e : v)
        e.afficher();
}
