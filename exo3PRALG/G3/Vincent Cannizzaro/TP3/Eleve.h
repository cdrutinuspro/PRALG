#ifndef ELEVE_H
#define ELEVE_H
#pragma once
#endif // ELEVE_H
// #include<Imagine/Graphics.h>
// using namespace Imagine;
#include <iostream>

class Eleve {
public:
    std::string name;
    int note;
    Eleve(std::string student_name, int student_grade) {
        name = student_name;
        note = student_grade;
    }
    void print();
};

class CompareNote {
public:
    int* ptr;
    bool decr;
    CompareNote(int* compt, bool decroissant = false) {
        ptr = compt;
        decr = decroissant;
    }
    bool operator()(const Eleve& A, const Eleve& B) const {
        *ptr += 1;
        if (decr) {
            return A.note>B.note;
        }
        else {
            return A.note<B.note;
        }
    }
};


class CompareNom {
public:
    int* ptr;
    bool decr;
    CompareNom(int* compt, bool decroissant = false) {
        ptr = compt;
        decr = decroissant;
    }
    bool operator()(const Eleve& A, const Eleve& B) const {
        *ptr += 1;
        if (decr) {
            return A.name>B.name;
        }
        else {
            return A.name<B.name;
        }
    }
    };



