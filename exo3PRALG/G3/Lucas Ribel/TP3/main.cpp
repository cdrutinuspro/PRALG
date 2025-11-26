#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Eleve {
private:
    std::string nom;
    int note;

public:
    Eleve() : nom(""), note(0) {}

    Eleve(const std::string& nomEleve, int noteEleve) : nom(nomEleve), note(noteEleve) {}

    std::string getNom() const { return nom; }
    void setNom(const std::string& nouveauNom) { nom = nouveauNom; }

    int getNote() const { return note; }
    void setNote(int nouvelleNote) { note = nouvelleNote; }
};

// Fonction pour générer un nom aléatoire
std::string genererNom(std::mt19937& gen) {
    std::uniform_int_distribution<> longueurDist(1, 10);
    std::uniform_int_distribution<> lettreDist('a', 'z');

    int longueur = longueurDist(gen);
    std::string nom(1, 'A' + (gen() % 26));  // Première lettre majuscule
    for (int i = 0; i < longueur; ++i) {
        nom += static_cast<char>(lettreDist(gen));
    }
    return nom;
}

// Foncteur de comparaison par nom
class CompareNom {
public:
    int* ptr;
    CompareNom(int* p = nullptr) : ptr(p) {}
    bool operator()(const Eleve& a, const Eleve& b) {
        if (ptr) ++(*ptr);
        return a.getNom() < b.getNom();
    }
};

// Foncteur de comparaison par note décroissante
class CompareNote {
public:
    int* ptr;
    CompareNote(int* p = nullptr) : ptr(p) {}
    bool operator()(const Eleve& a, const Eleve& b) {
        if (ptr) ++(*ptr);
        return a.getNote() > b.getNote();
    }
};

// Fonction d'affichage
void afficherEleves(const std::vector<Eleve>& eleves) {
    for (auto it = eleves.begin(); it != eleves.end(); ++it) {
        std::cout << "Nom: " << it->getNom() << ", Note: " << it->getNote() << std::endl;
    }
}

int main() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> noteDist(0, 20);

    std::vector<Eleve> eleves;
    const int nbEleves = 15;

    for (int i = 0; i < nbEleves; ++i) {
        eleves.emplace_back(genererNom(gen), noteDist(gen));
    }

    // Tri par nom
    int compteur = 0;
    CompareNom cmpNom(&compteur);
    std::sort(eleves.begin(), eleves.end(), cmpNom);

    std::cout << "Tri par nom (nombre de comparaisons): " << compteur << std::endl;
    afficherEleves(eleves);

    // Tri par note décroissante
    compteur = 0;
    CompareNote cmpNote(&compteur);
    std::sort(eleves.begin(), eleves.end(), cmpNote);

    std::cout << "Tri par note décroissante (nombre de comparaisons): " << compteur << std::endl;
    afficherEleves(eleves);

    return 0;
}
