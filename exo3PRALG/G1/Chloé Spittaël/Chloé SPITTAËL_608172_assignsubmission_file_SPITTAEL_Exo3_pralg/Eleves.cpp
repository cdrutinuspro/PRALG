#include "Eleves.h"


using namespace std;

/** Constructor. Initialize a student
*/
Eleve::Eleve(string Name1, int note1) {
    Name = Name1;
    note = note1;
}

/** Destructor. Delete a student
*/
Eleve::~Eleve() {
}

/**
*@return Name of this student
*/
string Eleve::getName() const {
    return Name;
}

/** Set Name of this student
*  @param Name1 information data to set
*/
void Eleve::setName(string Name1) {
    Name = Name1;
}

/**
* @return note of this student
*/
int Eleve::getnote() const {
    return note;
}

/** Set note of this student
*  @param note1 information data to set
*/
void Eleve::setnote(int note1) {
    note = note1;
}


/** Print the student name and note
*/
void Eleve::display() const {
    cout << Name << " : " << note << endl;  
}

/** Constructor. Initialize the functor (ptr = cmp = &compteur) for the count of note comparisons
* @param cmp pointer to the count adress
*/
CompareNote::CompareNote(int*cmp) {
    ptr = cmp;    
}

/** Note Comparison operator.
* @param st1,
* @param st2 students to be compared
*/
bool CompareNote::operator()(const Eleve& st1, const Eleve& st2) const {
    if (ptr) ++*ptr;
    return st1.getnote() > st2.getnote();
}

/** Constructor. Initialize the functor (ptr = cmp = &compteur) for the count of name comparisons
* @param cmp pointer to the count adress
*/
CompareNom::CompareNom(int* cmp) {
    ptr = cmp;
}

/** Name Comparison operator.
* @param st1,
* @param st2 students to be compared
*/
bool CompareNom::operator()(const Eleve& st1, const Eleve& st2) const {    
    if (ptr) ++*ptr;
    return st1.getName() < st2.getName();
}

/** Print the whole class1 with iterator
*  @param class1, vector of students
*/
void display_Class(const vector<Eleve>& Class1) {
    vector<Eleve>::const_iterator it = Class1.begin();
    for (; it != Class1.end(); ++it) {
        it->display();
    }
}
