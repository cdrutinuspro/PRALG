#pragma once
#include <iostream>
#include <vector>
// #include <Imagine/Common.h>

class Eleve {
    std::string nom;
    int note;
public:
    Eleve(std::string nom_, int note_); // Constructeur avec un nom et une note
    std::string Nom() const; // Getter pour le nom (evite l'anglissisme getNom())
    int Note() const; // Getter pour la note (evite l'anglissisme getNote())
    void mettreNom(std::string nouv_nom); // Permet la modification du nom (non utilisée mais toujours utile) (evite l'anglicisme setNom())
    void mettreNote(int nouv_note); // Permet la modification de la note (non utilisée mais toujours utile) (evite l'anglicisme setNote())
    void afficheEleve() const; // Affiche le nom et la note de l'eleve
};

std::vector<Eleve> genererEleves(int n); // Génère un vecteur aléatoire d'élèves de taille n
void afficherEleves(const std::vector<Eleve> &liste_eleves); // Affiche la liste d'élèves

class CompareNom{ // Foncteur permettant la comparaison des noms entre elèves
    int* ptr;
public :
    CompareNom(int* p) : ptr(p){} // Le constructeur prend necessairement un pointeur vers un compteur
    bool operator()(const Eleve& eleve1,const Eleve& eleve2) const;
};

class CompareNote{ // Foncteur permettant la comparaison des notes entre elèves
    int* ptr;
public:
    CompareNote(int* p) : ptr(p){} // Le constructeur prend necessairement un pointeur vers un compteur
    bool operator()(const Eleve& eleve1,const Eleve& eleve2) const;
};
