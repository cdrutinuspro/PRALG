/**
 * @file       Matrice.cpp
 * @author     Anwar Kardid (anwar.kardid@eleves.enpc.fr)
 * @date       2025-10-08
 * */

#include <iostream>
#include "Eleve.h"
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Displays all students in a vector with their names and grades
 * @param v Vector of students to display
 */
void affichage(vector<Eleve>& v)
{
    vector<Eleve>::iterator it = v.begin();
    for (; it != v.end(); ++it)
        cout << "Name : " << it->nom_ << ", Grade: " << it->note_ << endl;
    cout << endl;
}

/**
 * @brief Generates a vector of students with random names and grades
 * @param size Number of students to generate
 * @return Vector containing randomly generated students
 * 
 * Names start with uppercase letter (A-Z) followed by 1-9 lowercase letters.
 * Grades are random integers between 0 and 20.
 */
vector<Eleve> random_vector_eleves(int size)
{
    const int UPPERCASE_A = 65;
    const int LOWERCASE_A = 97; 
    const int ALPHABET_SIZE = 26;

    vector<Eleve> v_eleves;
    for(int i = 0; i < size; i++)
    {
        string nom;
        int longueur_ale = 1 + rand()%9;  // Random name length (1-9 chars)
        
        // Upper case first letter (A-Z: ASCII codes 65-90)
        nom += nom += char(UPPERCASE_A + rand() % ALPHABET_SIZE);;

        // Lower case letters (a-z: ASCII codes 97-122)
        for (int i = 0; i < longueur_ale; i++)
            nom += char(LOWERCASE_A + rand() % ALPHABET_SIZE);
            
        // Random grade between 0 and 20
        int note = rand()%21;

        // Create and add the current student to the vector
        v_eleves.push_back(Eleve(nom, note));
    }
    return v_eleves;
}

int main()
{
    srand(44);  // Seed for reproducible random generation
    int vector_size = rand() % 40;  // Random vector size (0-39)
    vector<Eleve> v_eleves = random_vector_eleves(vector_size);
    
    int compteur_nom = 0;   // Counter for name comparisons
    int compteur_note = 0;  // Counter for grade comparisons
    
    cout << " ----- Random vector of students created : " << endl; 
    affichage(v_eleves);
    
    // First sort: alphabetical sort by name (A -> Z)
    cout << " ----- Sorting according to the names : " << endl; 
    sort(v_eleves.begin(), v_eleves.end(), CompareNom(&compteur_nom));
    affichage(v_eleves);
    cout << "The number of past comparisons : " << compteur_nom << endl;
    cout << endl;
    
    // Second sort: descending sort by grades (20 -> 0)
    cout << " ----- Sorting according to the grades : " << endl; 
    sort(v_eleves.begin(), v_eleves.end(), CompareNote(&compteur_note));
    affichage(v_eleves);
    cout << "The number of past comparisons : " << compteur_note << endl;
    cout << endl;
}