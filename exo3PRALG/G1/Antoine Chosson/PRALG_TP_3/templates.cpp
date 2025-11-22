#include "templates.h"

Eleve::Eleve(std::string nm, int grd){
    /**
     * Constructor : create a student with given name and grade 
     * @param nm the name of the student 
     * @param grd the grade of the student 
     */
    name = nm; 
    note = grd; 
}

// Destructor  
Eleve::~Eleve() {
}

// Copy constructor 
Eleve::Eleve(const Eleve& reference_student){
    name = reference_student.name;
    note = reference_student.note;
}

// Name get method 
std::string Eleve::get_name() {
    return name;
}

// Grade get method 
int Eleve::get_grade() {
    return note;
}

// CompareNote Constructor 
CompareNote::CompareNote(int* counter) : ptr(counter){
}

bool CompareNote::operator()(Eleve eleve1, Eleve eleve2){
    /**
     * Operator that compares two students according to their grade 
     * @param eleve1 the first student 
     * @param eleve2 the second student 
     * @return if grade of 1st student is superior to second 
     */
    int note1 = eleve1.get_grade();
    int note2 =  eleve2.get_grade();
    (*ptr)++;
    return note1 > note2;
}

// CompareNom Constructor 
CompareNom::CompareNom(int* counter) : ptr(counter){
}

bool CompareNom::operator()(Eleve eleve1, Eleve eleve2){
    /**
     * Operator that sorts two students in alphabetical order
     * @param eleve1 the first student 
     * @param eleve2 the second student 
     * @return if eleve 1 comes first in alphabetical order 
     */
    std::string nom1 = eleve1.get_name();
    std::string nom2 = eleve2.get_name();
    int num_letters = std::min(nom1.size(),nom2.size());
    int i = 0;
    (*ptr)++;
    while(i < num_letters){
        if (nom1[i] == nom2[i]){ // if the two letters are the same, check next letter 
            i++;
        }
        else {
            return nom1[i] > nom2[i];
            break;
        }
    }
}



