#pragma once
#include <iosfwd>
#include <random>
#include <string>
#include <vector>

struct Eleve {
    std::string nom;  
    int note;         
};

std::ostream& operator<<(std::ostream& os, const Eleve& e);

struct CompareNom {
    int* compteur = nullptr;
    bool operator()(const Eleve& a, const Eleve& b) const;
};

struct CompareNote {
    int* compteur = nullptr;
    bool operator()(const Eleve& a, const Eleve& b) const;
};

std::string nom_aleatoire(std::mt19937& rng);
std::vector<Eleve> genere_echantillon(std::size_t N, std::uint64_t seed = std::random_device{}());

void afficher(const std::vector<Eleve>& v, const std::string& titre);

