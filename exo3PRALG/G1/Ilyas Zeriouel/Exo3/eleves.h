#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Eleve {
    std::string nom;
    int note;
public:
    Eleve(std::string name, int mark);
    int getMark() const;
    std::string getName() const;
    void setData(std::string name, int mark);
};

class CompareNotes {
    int* ptr;
public :
    CompareNotes(int* p);
    bool operator ()( const Eleve& A ,const  Eleve& B ) const {
        ++*ptr;
        int A_mark = A.getMark();
        int B_mark = B.getMark();
        return A_mark>B_mark;
    }
} ;

class CompareNoms {
    int* ptr;
public :
    CompareNoms(int* p);
    bool operator ()( const Eleve& A ,const  Eleve& B ) const {
        ++*ptr;
        std::string A_name = A.getName();
        std::string B_name = B.getName();
        return A_name<B_name;
    }
} ;

void print(const std::vector<Eleve>& V);
void decreasing_names(std::vector<Eleve>& eleves, int& compteur);
void decreasing_marks(std::vector<Eleve>& eleves, int& compteur);
