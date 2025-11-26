#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>


// Classe Eleve
class Eleve{
    std::string nom ;
    int note ;
public :
    // constructeur
    Eleve(std::string Nom, int Note);

    // getteur nom, note
    std::string getNom() const ;
    int getNote() const ;

    // afficher nom et note
    void affichageNom() const ;
    void affichageNote() const ;
};


// // // Foncteurs
// Foncteur pour comparer les noms
class CompareName{
    int* ptr;
public :
    // constructeur par defaut
    CompareName() : ptr(nullptr) {}
    // constructeur
    CompareName(int& compteur) : ptr(&compteur) {}
    // get compteur
    int getCompteur() const {return (ptr != nullptr) ? *ptr : 0;}
    // operateur
    bool operator()(const Eleve& Eleve1, const Eleve& Eleve2) const {
        if (ptr == nullptr) {
            throw std::runtime_error("Erreur : pointeur non initialisé dans CompareName::operator()");
        }
        ++(*ptr);
        return Eleve1.getNom() < Eleve2.getNom() ;
    }
};

// Foncteur pour comparer les notes
class CompareNote{
    int* ptr;
public :
    // constructeur par defaut
    CompareNote() : ptr(nullptr) {}
    // constructeur
    CompareNote(int& compteur) : ptr(&compteur) {}
    // get compteur
    int getCompteur() const {return (ptr != nullptr) ? *ptr : 0;}
    // operateur
    bool operator()(const Eleve& Eleve1, const Eleve& Eleve2) const {
        if (ptr == nullptr) {
            throw std::runtime_error("Erreur : pointeur non initialisé dans CompareName::operator()");
        }
        ++(*ptr);
        return Eleve1.getNote() < Eleve2.getNote() ;
    }
};


// // // Afficher les vecteurs
void affichageNoms(std::vector<Eleve>& eleves) ;
void affichageNotes(std::vector<Eleve> &eleves) ;
