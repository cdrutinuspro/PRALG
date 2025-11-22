#include <iostream>

using namespace std;
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

struct Eleve {
    string nom;
    int note;
};

struct CmpNom {
    int* cnt;
    CmpNom(int* p = nullptr) : cnt(p) {}
    bool operator()(const Eleve& a, const Eleve& b) const {
        if (cnt) (*cnt)++;
        return a.nom < b.nom;
    }
};

struct CmpNote {
    int* cnt;
    CmpNote(int* p = nullptr) : cnt(p) {}
    bool operator()(const Eleve& a, const Eleve& b) const {
        if (cnt) (*cnt)++;
        return a.note > b.note;
    }
};

static string randomName(mt19937& rng) {
    uniform_int_distribution<int> L(1, 10);
    uniform_int_distribution<int> lo('a', 'z');
    uniform_int_distribution<int> up('A', 'Z');
    int len = L(rng);
    string s; s.reserve(len + 1);
    s.push_back(char(up(rng)));
    for (int i = 0; i < len; i++) s.push_back(char(lo(rng)));
    return s;
}

static vector<Eleve> makeClass(size_t n, mt19937& rng) {
    uniform_int_distribution<int> notes(0, 20);
    vector<Eleve> v; v.reserve(n);
    for (size_t i = 0; i < n; i++) v.push_back({ randomName(rng), notes(rng) });
    return v;
}

static void printVec(const vector<Eleve>& v, const string& titre) {
    cout << "\n== " << titre << " ==\n";
    for (vector<Eleve>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->nom << "  " << it->note << "\n";
    }
}


int main() {
    random_device rd; mt19937 rng(rd());
    vector<Eleve> v = makeClass(30, rng);
    printVec(v, "Donnees initiales");

    {   vector<Eleve> t = v; int c = 0;
        sort(t.begin(), t.end(), CmpNom(&c));
        printVec(t, "Tri alphabetique (nom)");
        cout << "Comparaisons (nom): " << c << "\n";
    }
    {   vector<Eleve> t = v; int c = 0;
        sort(t.begin(), t.end(), CmpNote(&c));
        printVec(t, "Tri par note decroissante");
        cout << "Comparaisons (note): " << c << "\n";
    }
    return 0;
}
