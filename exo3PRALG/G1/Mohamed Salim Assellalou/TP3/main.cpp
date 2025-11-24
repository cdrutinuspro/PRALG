#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Eleve {
public:
    string nom;
    int note;
    Eleve(string n, int s) {
        nom = n;
        note = s;
    }
};

class CompareNom {
public:
    int* ptr;
    CompareNom() {
        ptr = 0;
    }
    bool operator()(Eleve& a, Eleve& b) {
        if (ptr)
            ++(*ptr);
        return a.nom < b.nom;
    }
};

class CompareNote {
public:
    int* ptr;
    CompareNote() {
        ptr = 0;
    }
    bool operator()(Eleve& a, Eleve& b) {
        if (ptr)
            ++(*ptr);
        return a.note > b.note;
    }
};

string nomAlea() {
    string s;
    s += char('A' + rand() % 26);
    int n = 1 + rand() % 10;
    for (int i = 0; i < n; i++) {
        s += char('a' + rand() % 26);
    }
    return s;
}

void afficher(vector<Eleve>& v) {
    vector<Eleve>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << it->nom << " " << it->note << endl;
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "combien d'eleves: ";
    if (!(cin >> n) || n <= 0)
        n = 10;

    vector<Eleve> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        v.push_back(Eleve(nomAlea(), rand() % 21));
    }
    cout << "\n initial: \n";
    afficher(v);

    int compteur = 0;
    CompareNom cmpNom;
    cmpNom.ptr = &compteur;
    sort(v.begin(), v.end(), cmpNom);
    cout << "\n  tri nom (alphabetique): \n";
    afficher(v);
    cout << "comparaisons: " << compteur << endl;

    compteur = 0;
    CompareNote cmpNote;
    cmpNote.ptr = &compteur;
    sort(v.begin(), v.end(), cmpNote);
    cout << "\n   tri note (decroissant):\n";
    afficher(v);
    cout << "comparaisons: " << compteur << endl;

    return 0;
}
