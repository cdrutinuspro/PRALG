#include "student.h"

using namespace std;
string generate_name(){
    int length = rand()%10 + 1;
    string name = "";
    char lettre = 'A' + rand()%26;
    name += lettre;
    for (int i = 1; i < length ; i++){
        lettre = 'a' + rand()%26;
        name += lettre;
    }
    return name;
}
Eleve::Eleve(string n, int no, bool random) {
    if (random) {
        nom = generate_name();
        note = rand()%21;
    }
    else {
        nom = n;
        note = no;
    }
}
string Eleve::getNom() const {
    return nom;
}
int Eleve::getNote() const {
    return note;
}
void DisplayEleves(const vector<Eleve>& eleves){
    for (int i = 0; i < eleves.size(); i++) {
        cout << eleves[i].getNom() << " : " << eleves[i].getNote() << endl;
    }
}