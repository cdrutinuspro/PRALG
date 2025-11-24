#pragma once
#include <iostream>



class Eleve
{
    std::string name;
    int grade;

public:
    Eleve(std::string name, int note);
    std::string& get_name();
    int& get_grade();
};


//foncteur

class CompareNom{
    int* ptr;
public:
    CompareNom(int* counter){ptr = counter;}
    bool operator()(Eleve& a, Eleve& b){++*ptr; return (a.get_name() < b.get_name()); }
};


class CompareGrade{
    int* ptr;
public:
    CompareGrade(int* counter){ptr = counter;}
    bool operator()(Eleve& a, Eleve& b){++*ptr; return (a.get_grade() > b.get_grade()); }
};
