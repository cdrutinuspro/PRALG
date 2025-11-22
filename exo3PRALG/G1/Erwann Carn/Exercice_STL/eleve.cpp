#include "eleve.h"

Eleve::Eleve(string nom_el, int note_el){
    nom = nom_el;
    note = note_el;
}

int Eleve::getNote() const{
    return(note);
}

string Eleve::getNom() const{
    return(nom);
}

char lettre_minuscule() {
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    char c = alphabet[rand()%alphabet.size()];
    return(c);
}

char lettre_majuscule() {
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c = alphabet[rand()%alphabet.size()];
    return(c);
}

void generate(vector<Eleve>& out, int max_count){
    int nb_element = rand()%max_count +1 ;
    for (int i =0; i<nb_element; i++){
        int lettres = rand()%10 + 1;
        int note = rand()%21;
        string nom;
        nom.push_back(lettre_majuscule());
        for (int j=0; j<lettres; j++ ){
            nom.push_back(lettre_minuscule());
        }
        out.emplace_back(move(nom), note);
    }
}

ostream& operator<<(ostream& os, const Eleve& e) { //aide de chat gpt pour cet operateur
    return os << e.nom << " (" << e.note << ")";
}


