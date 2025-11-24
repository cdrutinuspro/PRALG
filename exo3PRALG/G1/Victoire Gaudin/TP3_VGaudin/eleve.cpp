#include "eleve.h"

Eleve::Eleve(string name0, int note0)
{
    name = name0;
    note = note0;
}

string Eleve::getname() const{
    return name;
}

int Eleve::getnote() const{
    return note;
}

int Eleve::generernotealeatoire(){
    return rand() % 21;

}

string Eleve::generernomaleatoire(){
    string nom;
    int longueur = rand() % 9; //longueur sans la première lettre, entre 0 et 9
    nom += 'A' + (rand() % 26);
    for(int i = 0; i < longueur; i++){
        nom += 'a' + (rand() % 26);
    }
    return nom;
}

void Eleve::remplirvecteur(vector<Eleve>& classe, int nb_eleves){
    for(int i = 0; i < nb_eleves; i ++){
        string nom = generernomaleatoire();
        int note = generernotealeatoire();
        classe.emplace_back(nom, note);
    }
   }

void Eleve::triervecteurnom(vector<Eleve>& classe, int* compteur){
    CompareNom cmp(compteur);
    sort(classe.begin(), classe.end(), cmp);
}

void Eleve::triervecteurnote(vector<Eleve>& classe, int* compteur){
   CompareNote cmp(compteur);
   std::sort(classe.begin(), classe.end(), cmp);
}

void Eleve::affichervecteur(const vector<Eleve>& classe){
    for(int i = 0; i < classe.size(); i++){
        cout << classe[i].getname() << ":" << classe[i].getnote() << endl;
    }
}

CompareNom::CompareNom(int* ptr0){
    ptr = ptr0;
}

bool CompareNom::operator()(const Eleve e1, const Eleve e2){
    ++(*ptr);
    return e1.getname() < e2.getname();
}

CompareNote::CompareNote(int* ptr0){
    ptr = ptr0;
}

bool CompareNote::operator()(const Eleve e1, const Eleve e2){
    ++(*ptr);
    return e1.getnote() < e2.getnote();
}

