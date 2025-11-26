#include "Eleve.h"

// question 3
bool CompareNom::operator()(const Eleve& eleve1, const Eleve& eleve2) const{
    string name1; string name2;
    eleve1.get_name(name1); eleve2.get_name(name2);
    ++*ptr; // question 5
    return (name1.compare(name2)<0); // see https://www.geeksforgeeks.org/cpp/stdstringcompare-in-c/ explaining compare()
}

bool CompareNote::operator()(const Eleve& eleve1, const Eleve& eleve2) const{
    int mark1; int mark2;
    eleve1.get_mark(mark1); eleve2.get_mark(mark2);
    ++*ptr; // question 5
    return (mark1>mark2);
}

// question 4
ostream& operator<<(ostream& str, const vector<Eleve>& eleves_vector){
    str << "name" << ", " << "mark" << endl;
    for(int i=0; i<eleves_vector.size(); i++){
        string name; int mark;
        eleves_vector.at(i).get(name,mark);
        str << name << ", " << mark << endl;
    }
    return str;
}
