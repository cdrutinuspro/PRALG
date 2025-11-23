#include "Eleve.h"
#include <iostream>
using namespace std;

Eleve::Eleve(string name, int note) {
    this->name = name;
    this->note = note;
}
Eleve::Eleve(const Eleve& elIn) {
    this->name = elIn.getName();
    this->note = elIn.getNote();
}
Eleve::~Eleve() {   }
string Eleve::getName() const {
    return name;
}
int Eleve::getNote() const {
    return note;
}
void Eleve::setName(string name) {
    this->name = name;
}
void Eleve::setNote(int note) {
    this->note = note;
}
string Eleve::getStringRep() const {
    return "Name: " + name + " | Note: " + to_string(note);
}

// foncteurs: 
CompareName::CompareName() {
    ptr = new int(0);
}
CompareName::~CompareName() {}
bool CompareName::operator()(Eleve el1, Eleve el2) const{
    ++*ptr;
    return el1.getName() < el2.getName();
}


CompareNote::CompareNote() {
    ptr = new int(0);
}
CompareNote::~CompareNote() {}
bool CompareNote::operator()(Eleve el1, Eleve el2) const {
    ++*ptr;
    return el1.getNote() < el2.getNote();
}
