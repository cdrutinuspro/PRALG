#pragma once
#include "Eleve.h"
#include <string>
using namespace std;

class CompareNom{
    int * ptr;
public:
    CompareNom(int * ptr_0): ptr(ptr_0) {}
    bool operator()(const Eleve& e1, const Eleve& e2) const {++*ptr; return e1.getName() < e2.getName(); }

};
