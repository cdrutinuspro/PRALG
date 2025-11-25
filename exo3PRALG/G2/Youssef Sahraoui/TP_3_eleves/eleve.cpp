#include "eleve.h"

Eleve::Eleve(string nom,int note){
    nom_eleve=nom;
    note_eleve=note;
}
string Eleve::nom() const{
    return nom_eleve;
}
int Eleve::note() const{
    return note_eleve;
}
void Eleve::modifie_note(int note){
    note_eleve=note;
}

CompareNom::CompareNom(int& cnt){
    cnt_ptr=&cnt;
}
CompareNote::CompareNote(int& cnt){
    cnt_ptr=&cnt;
}

bool CompareNom::operator()(Eleve eleve1,Eleve eleve2) const{
    ++(*cnt_ptr);
    return eleve1.nom()<eleve2.nom(); // ordre alphabétique
}
bool CompareNote::operator()(Eleve eleve1,Eleve eleve2) const{
    ++(*cnt_ptr);
    return eleve1.note()>eleve2.note(); // ordre décroissant
}

void affiche(const vector<Eleve>& eleves){
    cout<<"[, ";
    for(auto& eleve:eleves){
        cout<<eleve.nom()<<":"<<eleve.note()<<",";
    }
    cout<<" ]"<<endl;
}
