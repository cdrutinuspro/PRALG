#pragma once
#include <iostream>

using namespace std;

class Eleve{
    std::string name;
    int grade;
public :
    Eleve(string new_name,int new_grade){name=new_name; grade=new_grade;}
    void set_name(string new_name){name = new_name;};
    string get_name()const{return(name);};
    int get_grade()const {return(grade);};
    void display();
};

class CompareNom{
    int *ptr;
public:
    bool operator()(string name1,string name2);
};

class CompareNote{
    int *ptr;
    bool operator()(int i, int j);
};

class CompareEleve_note{
public:
    int *ptr;
    bool operator()(const Eleve& eleve1, const Eleve& eleve2);
};
class CompareEleve_nom{
public:
    int *ptr;
    bool operator()(const Eleve& eleve1, const Eleve& eleve2);
};

//Q4 affichage du vecteur eleves
template <class T>
void display(vector<T>& V) {
    typename vector<T>::iterator it;
    for (it = V.begin(); it != V.end(); ++it) {
        it->display();
    }
}
