#include "Eleve.h"

string operator+(const string& a, const char* b) {
    return a + string(b);
}

void display(vector<Eleve> classe, vector<int> ordre){
    assert(classe.size() == ordre.size());
    int length_classe = classe.size();
    for (int i = 0; i < length_classe; i++)
        classe[ordre[i]].displaycout();
}

int main() {
    srand(time(0));

    int compteur=0;

    int nombre_eleves = rand() % 100;
    vector<Eleve> classe(nombre_eleves);

    for (int i = 0; i < nombre_eleves; i++) {
        int note_etudiant = rand() % 21;
        classe[i].setNote(note_etudiant);

        int first_lettre_code = 65 + rand() % 26;
        string nom_etudiant(1, static_cast<char>(first_lettre_code));

        int nombre_lettres = 1 + rand() % 10;
        for (int j = 0; j < nombre_lettres; j++) {
            char rand_letter = static_cast<char>(97 + rand() % 26);
            nom_etudiant += rand_letter;
        }

        classe[i].setNom(nom_etudiant);
        //classe[i].displaycout();
    }

    vector<int> ordre(nombre_eleves);
    for (int i = 0; i < nombre_eleves; i++)
        ordre[i] = i;

    /*
    CompareNom cmp_nom(classe);
    cmp_nom.ptr = &compteur;
    cout<<"============ordre alphabétique============="<<endl;
    sort(ordre.begin(), ordre.end(), cmp_nom);
    display(classe, ordre);
    cout<<"nombre de comparaisons : "<<compteur<<endl;
    */
    /*
    CompareNote cmp_note(classe);
    cmp_note.ptr = &compteur;
    cout<<"==============ordre note===================="<<endl;
    sort(ordre.begin(), ordre.end(), cmp_note);
    display(classe, ordre);
    cout<<"nombre de comparaisons : "<<compteur<<endl;
    */

    CompareNoteNom cmp_note_nom(classe);
    cmp_note_nom.ptr = &compteur;
    cout<<"============ordre note / alphabétique============="<<endl;
            sort(ordre.begin(), ordre.end(), cmp_note_nom);
    display(classe, ordre);
    cout<<"nombre de comparaisons : "<<compteur<<endl;

    /*
    // Code ASCII
    char c = 'A';
    int code = static_cast<int>(c);
    cout << "Le code ASCII de " << c << " est " << code << endl;

    int code_ascii = 65;
    char char_ascii = static_cast<char>(code_ascii);
    cout << "Le char ASCII de " << code_ascii << " est " << char_ascii << endl;


    // Saisie d'un caractère
    char input;
    cout << "Entrez un caractère : ";
    cin >> input;
    cout << "Code ASCII : " << static_cast<int>(input) << endl;
    */
    return 0;
}
