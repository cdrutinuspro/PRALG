#include "eleve.h"
#include <iostream>
#include <list>
#include <stdexcept>
#include <queue>
using namespace std;

//Constructeur de la classe élève
//en fait je ne sais pas si c'est vraiment utile alors que j'ai fais le choix
//de mettre une méthode setName et setNote. Donc en fait il faudrait initialiser
//l'élève "vide" et après lui donner un nom et une note
Eleve::Eleve(std::string aName, int aNote){
    name = aName;
    note = aNote;
}

//Destructeur de la clasee élève 
Eleve::~Eleve(){
}

//Méthode de la classe élève pour modifier la note de l'élève
void Eleve::SetNote(int d){
    note = d;
}

//Méthode de la classe élève pour obtenir la note de l'élève
int Eleve::GetNote() const{
    return note;
}

//Méthode de la classe élève pour modifier le nom de l'élève
void Eleve::SetName(std::string str){
    name = str;
}

//Méthode de la classe élève pour obtenir le nom de l'élève
std::string Eleve::GetName() const{
    return name;
}


//foncteur pour comparer les notes 
bool CompareNote::operator()(Eleve& eleve1, Eleve& eleve2) {
    //j'ai mis des "&" pour ne pas copier les eleves, comme dans le tp matrice
    ++(*ptr); //on incrémente 
    return eleve1.GetNote() < eleve2.GetNote();
}

//foncteur pour comparer les noms
bool CompareName::operator()(Eleve& eleve1, Eleve& eleve2) {
    //même méthode qu'avant
    ++(*ptr);
    return eleve1.GetName() < eleve2.GetName();
}


void AfficheEleves(const std::vector<Eleve>& groupe_eleves){
    for (auto it = groupe_eleves.begin(); it != groupe_eleves.end(); ++it) {
        //ici on utilise un itérateur, comme vu dans le cours
        //j'ai trouvé sur internet l'utilisation de "auto" car je ne voulais pas écrire
        //une expression trop lourde pour désigner l'itérateur
        cout << "Nom de l'élève : " << it->GetName() << "/Note de l'élève : " << it->GetNote() << endl;
        //dans la boucle, it est un itérateur sur des élèves, donc on peut utiliser les get
    }
}

