#pragma once
#include <string>
#include <iostream>
#include <vector>

class Eleve {
    std::string nom ;
    int note ;
public :

    Eleve(std::string str, int n) ;
    Eleve ();

   std::string get_nom() const;
   int get_note() const;

   void change_note(int n);

   void print() const;

};

void random_init();
char random_lettre_min();
std::string random_nom();
int random_note();
Eleve random_eleve();
std::vector<Eleve> random_class(int nb_eleves) ;

void afficher_classe(const std::vector<Eleve>& classe) ;
