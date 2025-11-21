#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int n=10; // #eleves

struct Eleve {
    string nom;
    int note;
    Eleve();
};

Eleve::Eleve() {
    nom.push_back('A'+rand()%26);
    int len = 1+rand()%10;
    for(int i=0; i<len; i++)
        nom.push_back('a'+rand()%26);
    note = rand() % 21;
}

struct CompareNom {
    int* compteur;
    CompareNom(int* c): compteur(c) { *c=0; }
    bool operator()(const Eleve& e1, const Eleve& e2) const {
        ++*compteur; return e1.nom < e2.nom;
    }
};

struct CompareNote {
    int* compteur;
    CompareNote(int* c): compteur(c) { *c=0; }
    bool operator()(const Eleve& e1, const Eleve& e2) const {
        ++*compteur; return e1.note > e2.note;
    }
};

void print(const vector<Eleve>& v) {
    for(vector<Eleve>::const_iterator it=v.begin(); it!=v.end(); ++it)
        cout << it->nom << ": " << it->note << std::endl;
}

int main() {
    srand(time(0));
    std::vector<Eleve> v;
    for(int i=0; i<n; i++)
        v.push_back( Eleve() );
    int c;
    sort(v.begin(), v.end(), CompareNom(&c));
    cout << "** Tri nom: " << c << " comparaisons" << endl;
    print(v);
    sort(v.begin(), v.end(), CompareNote(&c));
    cout << "** Tri merite: " << c << " comparaisons" << endl;
    print(v);
    return 0;
}
