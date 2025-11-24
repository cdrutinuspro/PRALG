#include "eleve.h"

using namespace std;
// using namespace Imagine;


Eleve::Eleve(string nom_, int note_){
    nom = nom_;
    note = note_;
}

string Eleve::Nom() const{
    return nom;
}

int Eleve::Note() const{
    return note;
}

void Eleve::mettreNom(std::string nouv_nom){
    nom = nouv_nom;
}

void Eleve::mettreNote(int nouv_note){
    note = nouv_note;
}

void Eleve::afficheEleve() const{
    cout << "Note de "<< nom << " :" << note <<endl;
}

std::vector<Eleve> genererEleves(int n){
    std::vector<Eleve> liste_eleves;
    for (int i=0; i < n; i++){
        int note = rand()%20;
        string name = "";
        char Maj = 'A' + rand()%25;
        name += Maj;
        int nb_lettres = rand()%10+1;
        for (int j=0; j < nb_lettres; j++){
            char caractere = 'a' + rand()%25;
            name += caractere;
        }
        liste_eleves.push_back(Eleve(name,note));
    }
    return liste_eleves;
}

bool CompareNom::operator()(const Eleve &eleve1, const Eleve &eleve2) const{
    ++*ptr;
    return eleve1.Nom() < eleve2.Nom();
}

bool CompareNote::operator()(const Eleve& eleve1,const Eleve& eleve2) const{
    ++*ptr;
    return eleve1.Note() > eleve2.Note();
}

void afficherEleves(const std::vector<Eleve> &liste_eleves){
    vector<Eleve>::const_iterator it = liste_eleves.begin();
    for (; it!=liste_eleves.end(); ++it)
        it->afficheEleve();
}
