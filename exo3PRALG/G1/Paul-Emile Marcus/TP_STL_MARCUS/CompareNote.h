#pragma once
#include "Eleve.h"

class CompareNote{
    int * ptr;
public:
    CompareNote(int * ptr_0): ptr(ptr_0) {}
    bool operator()(const Eleve& e1, const Eleve& e2) const { ++* ptr; return e1.getGrade() < e2.getGrade(); }

};
