#pragma once
#include <vector>
#include <iostream>
#include <string>
// #include <Imagine/Images.h>
// #include <Imagine/Graphics.h>
#include <cstdlib>

// using namespace Imagine ;
using namespace std;

class Eleve {
    string name;
    int grade;
public :
    Eleve(string name0,int grade0);
    Eleve(const Eleve& student);
    string student_name()const {return name;}
    int student_grade()const {return grade;}
};

class CompareNote {
    int * ptr;
    bool decr;
public:
    CompareNote(int* ptr0, bool decroissant){
        ptr=ptr0;
        decr=decroissant; //Cet attribut sert à indiquer comment on va éffectuer notre classement
    }
    bool operator() (const Eleve& student1, const Eleve& student2) const{
        ++(*ptr);
        return decr?(student1.student_grade()>student2.student_grade()):(student1.student_grade()<student2.student_grade());
    }
    int get_counter() const {return (*ptr);}
};

class CompareNom {
    int * ptr;
    bool decr;
public:
    CompareNom(int* ptr0,bool decroissant){
        ptr=ptr0;
        decr=decroissant; //Cet attribut sert à indiquer comment on va éffectuer notre classement
    }
    bool operator()(const Eleve& student1, const Eleve& student2) const{
        ++(*ptr);
        return decr?(student1.student_name()>student2.student_name()):(student1.student_name()<student2.student_name());
    }
    int get_counter() const {return (*ptr);}
};
