#ifndef ELEVE_H
#define ELEVE_H

#endif // ELEVE_H
// #include <Imagine/Images.h>
// #include <Imagine/Graphics.h>
#include <iostream>

// using namespace Imagine;
using namespace std;

//Question 1

/**
 * @brief Représente un élève avec un nom et une note.
 *
 * Fournit des accesseurs simples et un mutateur pour la note.
 */

class Eleve{
    std::string nom;
    int note;
public:
    /**
     * @brief Construit un élève.
     * @param name Nom de l'élève.
     * @param grade Note de l'élève (0..20).
     */
    Eleve(std::string name,int grade);

    /**
     * @brief Modifie la note.
     * @param grade Nouvelle note (0..20).
     */
    void SetNote(int grade);
    /**
     * @brief Retourne la note.
     * @return La note de l'élève.
     */
    int GetNote() const;

    /**
     * @brief Retourne le nom.
     * @return Le nom de l'élève.
     */
    std::string GetNom() const;
};

//Question 3


/**
 * @brief Foncteur de comparaison par nom (ordre alphabétique croissant).
 *
 * Possède un pointeur vers un compteur de comparaisons qui est incrémenté
 * à chaque appel de l'opérateur de comparaison.
 */
class CompareNom{
    int* ptr;
public:
    /**
     * @brief Construit un comparateur par nom.
     * @param p Pointeur vers un entier compteur (optionnel, peut valoir nullptr).
     */
    CompareNom(int* p = nullptr) : ptr(p) {}
    /**
     * @brief Compare deux élèves par leur nom (ordre alphabétique croissant).
     * @param e1 Premier élève.
     * @param e2 Second élève.
     * @return true si e1 < e2 selon le nom, false sinon.
     *
     * Incrémente @c *ptr si @c ptr n'est pas nul.
     */
    bool operator()(Eleve e1, Eleve e2){
        if (ptr) ++(*ptr);//Question 5
        return e1.GetNom()<e2.GetNom();
    }

};

/**
 * @brief Foncteur de comparaison par note (ordre décroissant).
 *
 * Possède un pointeur vers un compteur de comparaisons qui est incrémenté
 * à chaque appel de l'opérateur de comparaison.
 */

class CompareNote{
    int* ptr;
public:
    /**
     * @brief Construit un comparateur par note (décroissant).
     * @param p Pointeur vers un entier compteur (optionnel, peut valoir nullptr).
     */
    CompareNote(int* p = nullptr) : ptr(p) {}


    /**
     * @brief Compare deux élèves par leur note (ordre décroissant).
     * @param e1 Premier élève.
     * @param e2 Second élève.
     * @return true si note(e1) > note(e2), false sinon.
     *
     * Incrémente @c *ptr si @c ptr n'est pas nul.
     */
    bool operator()(Eleve e1, Eleve e2){
        if (ptr) ++(*ptr);//Question 5
        return e1.GetNote()>e2.GetNote();
    }
};
