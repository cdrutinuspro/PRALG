// #include<Imagine/Graphics.h>
#include "eleve.h"
#include <vector>
// using namespace Imagine;
using namespace std;

const int NbEleves = 15;

void afficheNoms(const vector<Eleve>& vecteurEleves){
    for (int i=0; i<NbEleves; i++)
        cout<<vecteurEleves[i].getNom()<<" ";
    cout <<endl;
}

void afficheNotes(const vector<Eleve> &vecteurEleves){
    for (int i=0; i<NbEleves; i++)
        cout<<vecteurEleves[i].getNote()<<" ";
    cout <<endl;
}


int main(){
    vector<Eleve> vecteurEleves(NbEleves);
    int compteur = 0;

    CompareNote cmpNote(&compteur);
    sort(vecteurEleves.begin(),vecteurEleves.end(),cmpNote);
    afficheNotes(vecteurEleves);
    cout<<"On a fait "<<compteur<<" comparaisons"<<endl;
    cout << "Here";
    compteur = 0;
    cout << "Here";
    CompareNom cmpNom(&compteur);
    sort(vecteurEleves.begin(),vecteurEleves.end(),cmpNom);
    afficheNoms(vecteurEleves);
    cout<<"On a fait "<<compteur<<" comparaisons"<<endl;

    return 0;
}
