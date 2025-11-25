#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Eleve.h"

// -------------------- Comparators --------------------
// Notes:
// - std::sort expects a strict-weak-order comparator.
// - For descending order, prefer (b < a) to keep it strict (using '>' is also fine).
// - We optionally count comparisons via an int* counter (may be nullptr).
// - Add a tie-break on the other field to get a deterministic total order.

class CompareNote;
class CompareNom;

class CompareNote {
private:
    int* ptr = nullptr;       // comparison counter; nullptr means "don't count"
    const bool ascending;     // true: ascending by note; false: descending

public:
    // Asc/desc only (counter defaults to nullptr)
    explicit CompareNote(bool asc)
        : ptr(nullptr), ascending(asc) {}

    // Counter only (ascending by default)
    explicit CompareNote(int* counter)
        : ptr(counter), ascending(true) {}

    // Asc/desc + counter
    CompareNote(bool asc, int* counter)
        : ptr(counter), ascending(asc) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++*ptr;

        if (a.getNote() != b.getNote()) {
            // Ascending: a < b  |  Descending: b < a
            return ascending ? (a.getNote() < b.getNote())
                             : (b.getNote() < a.getNote());
        }

        // Tie-break by name to ensure a total order (optional but recommended)
        return ascending ? (a.getNom() < b.getNom())
                         : (b.getNom() < a.getNom());
    }
};

class CompareNom {
private:
    int* ptr = nullptr;       // comparison counter; nullptr means "don't count"
    const bool ascending;     // true: A..Z; false: Z..A

public:
    // Counter only (ascending by default)
    explicit CompareNom(int* counter)
        : ptr(counter), ascending(true) {}

    // Asc/desc only
    explicit CompareNom(bool asc)
        : ptr(nullptr), ascending(asc) {}

    // Asc/desc + counter
    CompareNom(bool asc, int* counter)
        : ptr(counter), ascending(asc) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++*ptr;

        if (a.getNom() != b.getNom()) {
            // Ascending: a < b  |  Descending: b < a
            return ascending ? (a.getNom() < b.getNom())
                             : (b.getNom() < a.getNom());
        }

        // Tie-break by note
        return ascending ? (a.getNote() < b.getNote())
                         : (b.getNote() < a.getNote());
    }
};

// -------------------- Random data generation --------------------

std::string nom_aleatoire(std::mt19937& rng) {
    // Random length for the lowercase tail: [1..10]
    std::uniform_int_distribution<int> len_dist(1, 10);
    // Uppercase A..Z and lowercase a..z
    std::uniform_int_distribution<int> upper_dist(0, 25);
    std::uniform_int_distribution<int> lower_dist(0, 25);

    const int len = len_dist(rng);

    std::string nom;
    nom.reserve(1 + len);

    // First character uppercase
    nom.push_back(static_cast<char>('A' + upper_dist(rng)));

    // Then 1..10 lowercase characters
    for (int i = 0; i < len; ++i) {
        nom.push_back(static_cast<char>('a' + lower_dist(rng)));
    }
    return nom;
}

Eleve eleve_aleatoire(std::mt19937& rng) {
    // Uniform integer grade in [0..20]
    std::uniform_int_distribution<int> note_dist(0, 20);
    return Eleve(nom_aleatoire(rng), note_dist(rng));
}

std::vector<Eleve> generer_eleves(std::size_t n, std::uint32_t seed = std::random_device{}()) {
    std::mt19937 rng(seed);           // deterministic if seed is fixed
    std::vector<Eleve> v;
    v.reserve(n);
    for (std::size_t i = 0; i < n; ++i) {
        v.push_back(eleve_aleatoire(rng));
    }
    return v;
}

void afficher_eleves(const std::vector<Eleve>& students) {
    for (std::size_t i = 0; i < students.size(); ++i) {
        std::cout << "   " << i + 1 << ")  " << students[i].getNom()
                  << ": " << students[i].getNote() << '\n';
    }
}

// -------------------- Demo --------------------

int main() {
    int compteur = 0;
    std::vector<Eleve> students = generer_eleves(20);

    // Sort by name (ascending, counting comparisons)
    compteur = 0;
    std::sort(students.begin(), students.end(), CompareNom(true, &compteur));
    std::cout << "Students ordered alphabetically:\n";
    afficher_eleves(students);
    std::cout << "Number of comparisons:  " << compteur << "\n\n";

    // Sort by grade (descending, counting comparisons)
    compteur = 0;
    std::sort(students.begin(), students.end(), CompareNote(false, &compteur));
    std::cout << "Students ordered by grade:\n";
    afficher_eleves(students);
    std::cout << "Number of comparisons:  " << compteur << "\n";
}