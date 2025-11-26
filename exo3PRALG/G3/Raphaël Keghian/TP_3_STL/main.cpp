#include "eleve.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

template <typename Compare>
void display_sorted(vector<Eleve> v, Compare comp){
    sort(v.begin(), v.end(), comp);
    cout<<"Le nombre de comparaison effectuee pour le tri est : "<<comp.get_compteur()<<endl;
    cout<<" "<<endl;
    for(int i =0; i<v.size();i++){
        cout<<v[i].get_name()<<" a eu la note de : "<<v[i].get_grade()<<endl;
    }
    cout<<" "<<endl;
}

int main()
{
    srand((unsigned int)time(0));
    vector<Eleve> v;
    for(int i =0; i<10; i++){
        int rand_grade = rand()%21;
        string rand_name;
        rand_name += Alphabet[rand()%26];
        for(int j = 0; j <10; j++){
            if(rand()%2==0){
            rand_name += alphabet[rand()%26];
            }
        }
        v.push_back(Eleve(rand_name, rand_grade));
    }

    int* compteur = new int(0);
    CompareNom cmpNom(compteur);
    CompareNote cmpNote(compteur);

    display_sorted(v, cmpNom);
    display_sorted(v, cmpNote);

    delete compteur;

    return 0;
}
