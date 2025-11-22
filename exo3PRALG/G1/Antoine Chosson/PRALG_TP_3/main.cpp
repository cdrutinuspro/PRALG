#include "templates.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int display(std::vector<Eleve> eleves){
    /**
     * function that displays a given list of eleves and their grades using iterators
     * @param eleves a vector of eleves objects  
     * @return display of the list of the eleves and their grade 
     */
    for (std::vector<Eleve>::iterator t = eleves.begin(); t != eleves.end(); t++ ){
        std::cout << "name of student : " << t->get_name() << "  grade of student = " << t->get_grade() << std::endl;
    }
    return 0; 
}

int main(){

    const std::vector<std::string> minAlphabet{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    const std::vector<std::string> capAlphabet{"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    std::srand(std::time(nullptr)); // Initializing random generator 
    int n_eleves = 20; // Number of students in list 
    std::vector<Eleve> eleves; // Initial (student, grade) vector  

    int compteur; // comparaisons counter 

    for (int i = 0; i < n_eleves; i++){

        // Random grade generation : 
        int new_grade = std::rand() % 21;

        // Random name generation : 
        std::string new_name; 
        int rd_init_index = std::rand() % 26;
        new_name = new_name + capAlphabet[rd_init_index];
        int name_length = std::rand() % 10 + 1; 
        while (name_length > 0){
            int rd_letter_index = std::rand() % 26;
            new_name = new_name + minAlphabet[rd_letter_index];
            name_length--;
        }

        eleves.push_back(Eleve(new_name, new_grade));
    }

    std::cout << "unsorted list of students : " << std::endl;
    std::cout << "  " << std::endl; 
    display(eleves);
    std::cout << "  " << std::endl;

    std::sort(eleves.begin(), eleves.end(), CompareNote(&compteur));
    std::cout << "  " << std::endl;
    std::cout << "sorted list of students by grade : " << std::endl;
    std::cout << "  " << std::endl;
    display(eleves);
    std::cout << "  " << std::endl;
    std::cout << "n° of comparaisons done =  " << compteur << std::endl;
    std::cout << "  " << std::endl;
    compteur = 0; // resetting counter 

    std::sort(eleves.begin(), eleves.end(), CompareNom(&compteur));
    std::cout << "  " << std::endl;
    std::cout << "sorted list of students by alphabetical order : " << std::endl;
    std::cout << "  " << std::endl;
    display(eleves);
    std::cout << "  " << std::endl;
    std::cout << "n° of comparaisons done =  " << compteur << std::endl;

}


