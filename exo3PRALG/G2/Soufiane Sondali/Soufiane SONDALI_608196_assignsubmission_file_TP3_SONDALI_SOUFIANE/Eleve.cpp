#include "Eleve.h"

Eleve::Eleve(std::string ch, int mark){
    name = ch;
    note = mark;
}

std::string Eleve::getName() const{
    return name;
}

void Eleve::setName(std::string ch){
    name = ch;
    return;
}

int Eleve::getNote() const{
    return note;
}

void Eleve::setNote(int mark){
    note = mark;
    return;
}

CompareName::CompareName(const std::vector<Eleve>* e, int* compteur){
    Eleves = e;
    ptr = compteur;
}

bool CompareName::operator()(int i, int j) const{
    (*ptr)++;
    return (Eleves->at(i).getName() < Eleves->at(j).getName());
}

CompareNote::CompareNote(const std::vector<Eleve>* e, int* compteur){
    Eleves = e;
    ptr = compteur;
}

bool CompareNote::operator()(int i, int j) const{
    (*ptr)++;
    return (Eleves->at(i).getNote() > Eleves->at(j).getNote());
}

void display(int* tab, std::vector<Eleve>& e){
    for (int* it = tab; it != tab + NbEleve; ++it)
        cout << e[*it].getName() << " " << e[*it].getNote() << endl;
    cout << "END" << endl;
}
