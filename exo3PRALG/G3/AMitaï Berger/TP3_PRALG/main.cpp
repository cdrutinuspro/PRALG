// #include <QCoreApplication>
#include "Eleve.h"
#include <cstdlib>

string generateName(){
    int lenght=rand()%10;
    string name;
    char first_letter = 'A'+rand()%26;
    name+=first_letter;
    for(int i=0;i<lenght;i++){
        char c='a'+rand()%26;
        name+=c;}
    return name;
}

int generateNote(){return rand()%21;}

template<typename T> void displayOrder(const vector<Eleve>& v,const T& order){
    vector<Eleve> copy =v;
    sort(copy.begin(),copy.end(),order);
    for(Eleve e:copy){cout<<e.displayName()<<" "<<e.displayNote()<<endl;}
}

int main(){
    srand(1234);
    vector<Eleve> v;
    for(int i=0;i<20;i++){v.push_back(Eleve(generateName(),generateNote()));}
    CompareName name_order;
    CompareNote note_order;
    cout<<"Tri par noms"<<endl;
    cout<<endl;
    displayOrder(v,name_order);
    cout<<endl;
    cout<<"Tri par notes"<<endl;
    cout<<endl;
    displayOrder(v,note_order);
    return 0;
}
