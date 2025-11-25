#ifndef ELEVE_H
#define ELEVE_H

#include <vector>
#include <string>
#include <iostream>

class Eleve{
private:
    std::string name;
    int grade;

public:
    // Constructeurs et destructeurs
    Eleve(std::string n, int g);
    Eleve(const Eleve& other);
    ~Eleve();

    // Getters et setters
    std::string get_name() const;
    int get_grade() const;
    void set_name(std::string other_name);
    void set_grade(int other_grade);

    // Autre
    void show();
};

struct CompareNom {
    int* ptr;
    CompareNom(int* c = nullptr) : ptr(c) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++(*ptr);
        return a.get_name() < b.get_name();
    }
};

struct CompareNote {
    int* ptr;
    CompareNote(int* c = nullptr) : ptr(c) {}

    bool operator()(const Eleve& a, const Eleve& b) const {
        if (ptr) ++(*ptr);
        return a.get_grade() > b.get_grade(); // tri décroissant
    }
};


#endif // ELEVE_H
