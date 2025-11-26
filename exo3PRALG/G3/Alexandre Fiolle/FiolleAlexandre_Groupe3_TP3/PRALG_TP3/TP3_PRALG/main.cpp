// Project : TP3 PRALG
// Year : 2025
// Student : Alexandre FIOLLE

#include <iostream>
using namespace std;
#include "Eleve.h"
// #include <Imagine/Graphics.h>
// using namespace Imagine; // to access intRandom()
#include <algorithm>

int main()
{
    // initRandom();
    // question 2
    // random number of students between 10 and 50
    int size = rand()%41 + 10; //intRandom(10,50);
    vector<Eleve> Eleves_vector(size);
    for(int i=0; i<size; i++){
        // random mark between 0 and 20
        int mark = rand()%21; //intRandom(0,20);
        // random number of lower cases
        int name_length = 1 + rand()%10; // intRandom(1,10);
        // random capital letter (we get it thanks to a random int and a conversion in ASCII)
        char maj = char(65 + rand()%26); //intRandom(65,90));
        // name of our student
        string name;
        name.push_back(maj);
        for(int k=0; k<name_length; k++){
            // random lower case (thanks ASCII)
            char min = char(97 + rand()%26); //intRandom(97,122));
            name.push_back(min);
        }
        (Eleves_vector.at(i)).set(name, mark); // student added to the vector of whole students
    }

    // question 4
    // alphabetical order
    int compteur_alph = 0; // question 6
    CompareNom cmp_alph;
    cmp_alph.ptr = &compteur_alph; // question 6
    std::sort(Eleves_vector.begin(), Eleves_vector.end(), cmp_alph);
    cout << "by alphabetical order" << endl;
    cout << Eleves_vector;
    cout << "number of comparisons by alphabetical order sorting: " << compteur_alph << endl; // question 7
    cout << "" << endl;

    // decreasing marks order
    int compteur_mark = 0; // question 6
    CompareNote cmp_mark;
    cmp_mark.ptr = &compteur_mark; // question 6
    std::sort(Eleves_vector.begin(), Eleves_vector.end(), cmp_mark);
    cout << "by decreasing marks order" << endl;
    cout << Eleves_vector;
    cout << "number of comparisons by decreasing marks order sorting: " << compteur_mark << endl; // question 7

    return 0;
}
