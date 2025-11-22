#pragma once
#include <string>
using namespace std;

class Eleve {
private:
    string nom;
    float moyenne;

public:
    // Constructeurs
    Eleve();
    Eleve(string n, float m);
    Eleve(const Eleve& other);

    // Destructeur
    ~Eleve();

    // Méthodes
    string getNom() const;
    float getMoyenne() const;
    void setMoyenne(float m);
};
