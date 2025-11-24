#include "eleve.h"

using namespace std;
void Eleve::display(){
    cout<<name<<" : "<<grade<<endl;
}

//Q3
bool CompareNom::operator()(string name1,string name2){
    ++*ptr;
    int compare_length = name1.size();
    if (name2.size()<compare_length){compare_length=name2.size();};
    for (int i = 0; i<compare_length;i++){
        if (name1[i]<name2[i]){
            return(true); //ordre alphabétique, ordre croissant des codes ascii
        };
        if (name1[i]>name2[i]){
            return(false); //ordre alphabétique, ordre croissant des codes ascii
        };
    };
    return(false);
}

bool CompareNote::operator()(int i, int j){
    ++*ptr;
    return(i<j);
}

bool CompareEleve_nom::operator()(const Eleve& eleve1, const Eleve& eleve2){
    ++*ptr;
    return(eleve1.get_name()<eleve2.get_name());
}

bool CompareEleve_note::operator()(const Eleve& eleve1, const Eleve& eleve2){
    ++*ptr;
    return(eleve1.get_grade()<eleve2.get_grade());
}

