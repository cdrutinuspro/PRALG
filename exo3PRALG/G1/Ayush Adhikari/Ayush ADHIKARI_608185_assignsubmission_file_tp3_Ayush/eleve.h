#pragma once
#include <string>
#include <iostream>


class Eleve
{
    //Nom de l'eleve
    std::string nom;
    //Note de l'eleve
    int note;
public:
    /**
     * Constructeur. Cree un eleve lambda avec une note à la moyenne.
     */
    Eleve(std::string nom1, int note1);
    /**
     * Constructeur. Cree un eleve dont dont le nom et la note sont donnees en arguments.
     * @param nom1 nom de l'eleve
     * @param note1 note de l'eleve
     */
    Eleve();
    /**
     * Getter. Renvoie le nom de l'eleve.
     * @return nom de l'eleve
     */
    std::string getNom() const;
    /**
     * Getter. Renvoie la note de l'eleve.
     * @return note de l'eleve
     */
    int getNote() const;
    /**
     * Setter. Modifie la note de l'eleve
     * @param new_note nouvelle note a appliquer
     */
    void setNote(int new_note);
};

//Retourne un eleve au nom, et a la note aleatoire comme demande selon l'ennonce
Eleve random_eleve();

//Operateur permettant l'affichage des eleves selon un formattage decrit dans l'operateur
std::ostream& operator<<(std::ostream& os, const Eleve& eleve);



class CompareNom{
    //Compteur du nombre d'utilisations de l'objet
    int *ptr;
    //booleen mis a true ssi le pointeur est alloue en memoire (ie ssi initialise par constructeur vide)
    bool to_delete;
public:
    //Constructeur, allouant de la memoire au pointeur
    CompareNom();
    //Constructeur, ptr est alors cmp
    CompareNom(int* cmp);
    //Destructeur, faisant appel a delete [] ssi to_delete est vraie
    ~CompareNom();
    //operateur du foncteur, renvoyant true si le premier nom est avant le deuxieme
    bool operator()(Eleve eleve1, Eleve eleve2);
};


class CompareNote{
    //Compteur du nombre d'utilisations de l'objet
    int *ptr;
    //booleen mis a true ssi le pointeur est alloue en memoire (ie ssi initialise par constructeur vide)
    bool to_delete;
public:
    //Constructeur, allouant de la memoire au pointeur
    CompareNote();
    //Constructeur, ptr est alors cmp
    CompareNote(int* cmp);
    //Destructeur, faisant appel a delete [] ssi to_delete est vraie
    ~CompareNote();
    //operateur du foncteur, renvoyant true si le premier nom est avant le deuxieme
    bool operator()(Eleve eleve1, Eleve eleve2);
};




