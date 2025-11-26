#include "eleve.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>    
using namespace std;


int main() {
    srand(time(0));
    //j'utilise la même méthode que j'ai utilisé dans le TP1 pour
    //la génération d'entiers aléatoires. 

    std::vector<Eleve> groupe; //création du vecteur d'élèves 

    int nb_eleve = 30; //choix arbitraire 

    for (int i = 0; i < nb_eleve; ++i){
        int one_note = rand()%21; //comme TP1, ici nombre aléatoire entre 0 et 20 
        
        std::string one_name;
        one_name += 'A' + rand()%26; //pour avoir une majuscule aléatoire entre A et Z
        //j'ai trouvé cette technique sur un forum sur internet.

        int longueur_minuscule = 1 + rand()%10; //nombre aléatoire de 1 à 10 
        for (int k = 0; k < longueur_minuscule; k++){
            one_name += 'a' + rand()%26; //idem que pour la majuscule
        }

        Eleve new_eleve(one_name, one_note); //on crée l'élève avec la note et le nom générés
        groupe.push_back(new_eleve); //on ajoute l'élève au groupe
    }
    
    //à ce stade, normalement le groupe est formé des nb_eleve élèves générés aléatoirement


    //Etape du tri par note
    int compteur_note = 0;
    CompareNote cmp_note;
    cmp_note.ptr = &compteur_note; //donc cmp_note est un pointeur qui pointe sur compteur_note (je crois)

    std::sort(groupe.begin(), groupe.end(), cmp_note);
    cout << "Liste des élèves après le tri par note : " << endl;
    cout << endl;
    AfficheEleves(groupe);
    cout << endl << "Nombre de comparaisons tri par note : " << compteur_note << endl;
    cout << endl;


    //Etape du tri par nom
    int compteur_name = 0;
    CompareName cmp_name;
    cmp_name.ptr = &compteur_name; //idem, pointe sur compteur_name

    std::sort(groupe.begin(), groupe.end(), cmp_name);
    cout <<"Liste des élèves après le tri par nom : " << endl;
    cout << endl;
    AfficheEleves(groupe);
    cout << endl << "Nombre de comparaisons tri par nom : " << compteur_name << endl;
    cout << endl;


    //Test du changement d'une note sur le nombre de comparaisons
    groupe[0].SetNote(20);

    int compteur_note2 = 0;
    CompareNote cmp_note2;
    cmp_note2.ptr = &compteur_note2; //donc cmp_note2 est un pointeur qui pointe sur compteur_note2 (je crois)

    std::sort(groupe.begin(), groupe.end(), cmp_note2);
    cout << "Liste des élèves après le tri par note en changeant une note à 20 : " << endl;
    cout << endl;
    AfficheEleves(groupe);
    cout << endl << "Nombre de comparaisons tri par note en changeant une note à 20 : " << compteur_note2 << endl;
    cout << endl;

    return 0;
}