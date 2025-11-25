#include "eleves.h"

//Constructeurs
//Vide : aléatoire
Eleve::Eleve(){
    int l = 1 +rand()%11;

    //En ASCII : alphabet majuscule de 65 à 90, minuscule de 97 à 122
    int lettreASCII = 65 + rand()%26;
    char lettre = lettreASCII;
    string nom0(1,lettre);

    for (int i = 0; i<l;i++){
        lettreASCII = 97 + rand()%26;
        lettre = lettreASCII;
        nom0.push_back(lettre);
    }

    nom = nom0;
    note = rand()%20;

}

//Basique
Eleve::Eleve(string nom0, int note0){
    nom = nom0;

    assert (note0 <=20 && note0>=0);
    note = note0;
}


//Renvoie la note de l'eleve
int Eleve::get_note() const{
    return note;
}

//Change la note de l'eleve
void Eleve::set_note(const int note0){
    assert (note0 <=20 && note0>=0);
    note = note0;
}

//Renvoie le nom de l'eleve
string Eleve::get_nom() const{
    return nom;
}


//Foncteur pour comparer les noms

bool CompareNom::operator()(const Eleve& a, const Eleve& b) const{
    string n1 = a.get_nom();
    string n2 = b.get_nom();
    *ptr+=1;
    return (n1.compare(n2)<0);

}

void CompareNom::set_compteur(int & compteur){
    ptr = &compteur;
}

//Foncteur pour comparer les notes


bool CompareNote::operator()(const Eleve& a, const Eleve& b)const{
    int n1 = a.get_note();
    int n2 = b.get_note();
    *ptr +=1;
    return n1>n2;
}

void CompareNote::set_compteur(int & compteur){
    ptr = &compteur;
}



