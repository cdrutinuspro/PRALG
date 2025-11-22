#include <stdlib.h>
#include "eleve.h"
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    srand(time({})); //Initializing random seed

    vector<Eleve> eleves = {};
    for (int i=0; i<10; i++){
        eleves.push_back(random_eleve()); //generating vector of random students
    }

    int compteur = 0;
    CompareNom cmp_nom(&compteur);

    sort(eleves.begin(), eleves.end(), cmp_nom); //sorting the vector

    vector<Eleve>::iterator it; //iterator

    //printing new order
    cout << "Alphabetical order :" << endl;
    for (it = eleves.begin(); it != eleves.end(); it++){
        cout << *it;
    }

    cout << "Etat du compteur après tri alphabétique : " << compteur << endl;

    compteur = 0;
    CompareNote cmp_note(&compteur);
    sort(eleves.begin(), eleves.end(), cmp_note); //sorting the vector

    //printing new order
    cout << endl;
    cout << "Grades order :" << endl;
    for (it = eleves.begin(); it != eleves.end(); it++){
        cout << *it;
    }

    cout << "Etat du compteur après tri des notes : " << compteur << endl;


    return 0;
}
