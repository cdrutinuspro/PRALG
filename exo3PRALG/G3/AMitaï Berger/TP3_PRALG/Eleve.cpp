#include "Eleve.h"


Eleve::Eleve(string s,int n){name=s;note=n;}
string const Eleve::displayName(){return name;}
int const Eleve::displayNote(){return note;}

bool CompareNote::operator()(Eleve a,Eleve b){
    return a.displayNote()>b.displayNote();
}

bool CompareName::operator()(Eleve a,Eleve b){
    return a.displayName()>b.displayName();
}
