#include "eleves.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>


std::ostream& operator<<(std::ostream& os, const Eleve& e) {
    os << e.nom << " : " << e.note;
    return os;
}

bool CompareNom::operator()(const Eleve& a, const Eleve& b) const {
    if (compteur) ++*compteur;
    return a.nom < b.nom;
}

bool CompareNote::operator()(const Eleve& a, const Eleve& b) const {
    if (compteur) ++*compteur;
    return a.note > b.note;                      
}

std::string nom_aleatoire(std::mt19937& rng) {

    std::uniform_int_distribution<int> len_dist(1, 10);
    std::uniform_int_distribution<int> up_dist('A', 'Z');
    std::uniform_int_distribution<int> low_dist('a', 'z');

    int len = len_dist(rng);
    std::string s;
    // std::string s;
    s = char(up_dist(rng));
    for (int i = 0; i < len; ++i)
        s += char(low_dist(rng));

    return s;

    }


std::vector<Eleve> genere_echantillon(std::size_t N, std::uint64_t seed) {
    std::mt19937 rng(static_cast<std::mt19937::result_type>(seed));
    std::uniform_int_distribution<int> note_dist(0, 20);

    std::vector<Eleve> v;
    v.reserve(N);
    for (std::size_t i = 0; i < N; ++i) {
        v.push_back(Eleve{nom_aleatoire(rng), note_dist(rng)});
    }
    return v;
}


void afficher(const std::vector<Eleve>& v, const std::string& titre) {
    std::cout << titre << std::endl;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << "\n";
    }
}
