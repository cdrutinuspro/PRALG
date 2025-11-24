#include "eleve.h"


const string ALPHABET[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
    "Q","R","S","T","U","V","W","X","Y","Z"};

const string alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p",
    "q","r","s","t","u","v","w","x","y","z"};

const int  N_eleves = 15;

void affiche(vector<Eleve> eleves){
    for (Eleve eleve : eleves){
        eleve.affiche();
    }
}

int compteur = 0;

int main(){
    vector<Eleve> eleves;
    // initRandom(); 
    for (int i=0; i<N_eleves; i++){
        string nm = ALPHABET[rand()%26];
        int lenName = rand()%9 +1;
        for (int k=0; k<lenName; k++){
            nm += alphabet[rand()%26]; 
        }
        
        eleves.push_back(Eleve(nm, rand()%21));
    }
    cout << "ORDRE ALPHABETIQUE" << endl;
    std::sort(eleves.begin(), eleves.end(), CompareNom(&compteur));
    affiche(eleves);
    cout << "------------------"<< endl;
    cout << compteur << " comparaisons effectuees." << endl;
    
    cout << endl;

    cout << "TRI PAR NOTE DECROISSANTE" << endl; 
    std::sort(eleves.begin(), eleves.end(), CompareNote(&compteur));
    affiche(eleves);
    cout << "------------------"<< endl;
    cout << compteur << " comparaisons effectuees." << endl;
 
    return 0;
}