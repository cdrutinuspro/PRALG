#include "eleve.h"

int main(){
    vector<Eleve> Eleves;
    srand(time(0));
    int num_eleves=1+rand()%100; // Entre 1 et 100
    for(int i=0;i<num_eleves;i++){
        string name;
        int num_miniscule=1+rand()%10;
        name+=((int)'A'+rand()%26); 
        /*
        (int)'A' donne le nombre associé à 'A' en ascii
        et donc 'A'=x;'B'=x+1;...;'Z'=x+25
        */
        for(int j=0;j<num_miniscule;j++){
            // Même logique que précedent
            name+=((int)'a'+rand()%26);
        
        }
        int note=rand()%21; // Entre 0 et 20
        Eleves.push_back(Eleve(name,note));
    }
    // Tri selon ordre alphabétique
    int cnt_CompNom=0;
    sort(Eleves.begin(),Eleves.end(),CompareNom(cnt_CompNom));
    // Affichage des élèves triés par ordre alphabétique : 
        affiche(Eleves);
    
    // Tri selon les notes décroissantes
    int cnt_CompNote=0;
    sort(Eleves.begin(),Eleves.end(),CompareNote(cnt_CompNote));
    // Affichage des élèves triés par ordre décroissant des notes :
        affiche(Eleves);
    // Affichage Compteurs
    cout<<"Tri avec ordre alphabétique compare entre les élèves : "<<cnt_CompNom<<" fois"<<endl;
    cout<<"Tri avec ordre décroissant compare entre les élèves : "<<cnt_CompNote<<" fois"<<endl;
    /*
    Le but d'introduire ces compteurs est pour voir
    le nombre de comparaison fait par la fonction sort
    dans les deux cas
    */
}