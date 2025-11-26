#include "Eleve.h"

const string minuscules = "abcdefghijklmnopqrstuvwxyz";
const string majuscules = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Eleve::Eleve()
{
    note = 0;
    nom = "";

}

void Eleve::afficher(){
    cout << "eleve: " << nom << " | note: " << note << endl;
}

int get_i(const string& abc, const char& letter){
    for(int i = 0; i< abc.size(); i++){
        if(abc[i]==letter){
            return i;
        }
    }
    return -1;
}

bool CompareNom::operator ()(Eleve e1,Eleve e2)const{
    if (ptr) ++(*ptr);
    string nom1 = e1.nom;
    string nom2 = e2.nom;
    int size = min(nom1.size(), nom2.size());
    if (get_i(majuscules, nom1[0]) == get_i(majuscules, nom2[0])) {
        for(int i = 0; i < size; i++) {
            if(get_i(minuscules, nom1[i]) < get_i(minuscules, nom2[i])){
                return true;
            }
            if(get_i(minuscules, nom1[i]) > get_i(minuscules, nom2[i])){
                return false;
            }

        }
    }
    if (get_i(majuscules, nom1[0]) < get_i(majuscules, nom2[0])){
        return true;

    }
    return false;
}

bool CompareNote::operator ()(Eleve e1,Eleve e2)const{
    if (ptr) ++(*ptr);
    return (e1.note > e2.note);
}

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> random_grade(0, 20);
uniform_int_distribution<> random_letter(0, 25);
uniform_int_distribution<> random_len(0, 10);




Eleve::Eleve(int note0, string nom0){
    note = note0;
    nom = nom0;
}

Eleve random_eleve(){

    string nom = "";
    int note = random_grade(gen);
    int len = random_len(gen);
    nom = nom + majuscules[random_letter(gen)];
    for(int i = 0; i<len; i++){
        nom = nom + minuscules[random_letter(gen)];
    }
    return Eleve(note, nom);
}


