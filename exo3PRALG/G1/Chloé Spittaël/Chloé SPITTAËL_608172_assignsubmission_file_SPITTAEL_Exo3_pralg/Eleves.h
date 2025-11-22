#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/** Node of a tree containing an integer at each node 
*/ 
class Eleve {
    /** Student name
    */
    string Name;    
    /** Student note
    */
    int note;

public:
    /** Constructor. Create a student    
    */
    Eleve(string Name1 ="", int note1 = 0);

    /** Destructor. Delete a student
     */
    ~Eleve();

    /**
    * @return Name of this student
    */
    string getName() const;

    /** Set Name of this student
    *  @param Name1 information data to set
    */
    void setName(string Name1);

    /**
    * @return note of this student
    */
    int getnote() const;

    /** Set note of this student
    *  @param note1 information data to set
    */
    void setnote(int note1);      

    /** Print the student name and note    
    */
    void display() const;  
};

/** Sorting out by note
*/
class CompareNote {
public:
    int* ptr = nullptr;
    CompareNote(int* cmp = nullptr);
    bool operator ( ) (const Eleve& st1, const Eleve& st2) const;
};

/** Sorting out by name
*/
class CompareNom {
public:
    int* ptr = nullptr;
    CompareNom(int* cmp = nullptr);
    bool operator ( ) (const Eleve& st1, const Eleve& st2) const;
};

/** Print the whole class
*/
void display_Class(const vector<Eleve>& Class1);


