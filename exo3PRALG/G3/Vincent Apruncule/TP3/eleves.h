#pragma once
#include <iostream>


// class élève avec name et grade en privé
//J'ai de plus implémenté get_name et get_grade pour récupérer les attributs en dehors de la classe et de pouvoir leurs attribuer des valeurs
class Eleve
{
    std::string name;
    int grade;

public:
    Eleve(std::string name, int note);
    std::string& get_name();
    int& get_grade();
};


//foncteur
// j'ai décidé de passé l'initialisation du pointeur dans le constructeur
//cela compare directement avec l'ordre alphabétique
class CompareNom{
    int* ptr;
public:
    CompareNom(int* compteur){ptr = compteur;}
    bool operator()(Eleve& a, Eleve& b){++*ptr; return (a.get_name() < b.get_name()); }
};


class CompareGrade{
    int* ptr;
public:
    CompareGrade(int* compteur){ptr = compteur;}
    bool operator()(Eleve& a, Eleve& b){++*ptr; return (a.get_grade() < b.get_grade()); }
};
