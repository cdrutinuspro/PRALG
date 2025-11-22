// Imagine++ project
// Project:  Exo3
// Student(s):

#include "Eleves.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
    srand((unsigned int)time(0));

    int n = 1 + rand() % (20);                              // Nb of students in the classe [1-20]
    vector <Eleve> Classe(n);                               // Class initialisation
    int compteur = 0;

    for (int i = 0; i < n; i++) {
        Classe[i].setnote(rand() % (21));                   // Student[i] note

        int Letter_nb = 1 + rand() % (10);                 // 1 to 10 letters
        char Initial_letter = 'A' + rand() % (26);         // Capital letter initialisation
        string student_name(1, Initial_letter);            // Construction of student name
        for (int j = 0; j < (Letter_nb); j++) {
            char letter = 'a' + rand() % (26);
            student_name = student_name + letter;
        }
        Classe[i].setName(student_name);                   // Student[i] name
    }
    cout << "Number of students in the class : " << n << endl;
    cout << "Class results : " << endl;          // Print of the whole class results
    display_Class(Classe);

    cout << endl;
    compteur = 0;
    sort(Classe.begin(), Classe.end(), CompareNote(&compteur));
    cout << "Class results sorted out by note : " << endl;          // Print of the whole class results sorted out by note
    display_Class(Classe);
    cout << "Number of comparisons for the sorting out by note : " << compteur << endl;

    cout <<endl;
    compteur = 0;
    sort(Classe.begin(), Classe.end(), CompareNom(&compteur));
    cout << "Class results sorted out by name : " << endl;          // Print of the whole class results sorted out by name
    display_Class(Classe);
    cout << "Number of comparisons for the sorting out by name: " << compteur << endl;

    return 0;
}

