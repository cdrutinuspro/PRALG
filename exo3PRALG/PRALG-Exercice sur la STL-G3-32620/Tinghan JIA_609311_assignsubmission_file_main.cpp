//
//  main.cpp
//  TP3_STL
//
//  Created by Tinghan on 19/10/2025.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Define a student class
class Eleve {
public:
    std::string nom;  // student name
    int note;         // student grade (0–20)

    Eleve(std::string n, int nt) : nom(n), note(nt) {}
};

// Functor for comparing by name (alphabetical order)
class CompareNom {
public:
    int* ptr;  // pointer to an integer counter

    // Constructor (default: no counter)
    CompareNom(int* p = nullptr) : ptr(p) {}

    // Overload operator() to compare two students
    bool operator()(const Eleve& a, const Eleve& b) {
        if (ptr) ++(*ptr);   // increment comparison counter
        return a.nom < b.nom; // sort alphabetically
    }
};

// Functor for comparing by grade (descending order)
class CompareNote {
public:
    int* ptr;

    CompareNote(int* p = nullptr) : ptr(p) {}

    bool operator()(const Eleve& a, const Eleve& b) {
        if (ptr) ++(*ptr);
        return a.note > b.note; // higher grade first
    }
};

// Generate a random name: one uppercase + 1–10 lowercase letters
std::string randomName() {
    int len = rand() % 10 + 1;
    std::string name;
    name += 'A' + rand() % 26;  // first letter uppercase
    for (int i = 0; i < len; ++i)
        name += 'a' + rand() % 26;
    return name;
}

// Print all students in a vector
void printEleves(const std::vector<Eleve>& v) {
    for (auto& e : v)
        std::cout << e.nom << " - " << e.note << std::endl;
}

int main() {
    srand(time(0));  // initialize random seed

    // Generate random students
    std::vector<Eleve> eleves;
    for (int i = 0; i < 10; ++i) {
        eleves.push_back(Eleve(randomName(), rand() % 21));
    }

    // --- Sort by name ---
    int compteurNom = 0;
    CompareNom cmpNom(&compteurNom);
    std::sort(eleves.begin(), eleves.end(), cmpNom);

    std::cout << "\n--- Sorted by Name ---\n";
    printEleves(eleves);
    std::cout << "Number of comparisons: " << compteurNom << "\n";

    // --- Sort by grade (descending) ---
    int compteurNote = 0;
    CompareNote cmpNote(&compteurNote);
    std::sort(eleves.begin(), eleves.end(), cmpNote);

    std::cout << "\n--- Sorted by Grade (Descending) ---\n";
    printEleves(eleves);
    std::cout << "Number of comparisons: " << compteurNote << "\n";

    return 0;
}
