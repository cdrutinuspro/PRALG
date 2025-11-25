// Project:  Elève
// Author: El Ouassaïdi Naïm
// #include <Imagine/Graphics.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include "Eleve.h"
using namespace std;
const int student_number = 25;

string randomName(){
    string name;
    char firstLetter='A'+rand()%26;
    name+=firstLetter;
    int max=rand()%10;
    for(int i=0;i<max;i++){
        char letter = 'a'+rand()%26;
        name+=letter;
    }
    return name;
}

void print(const vector<Eleve>& A){
    for (int i = 0;i<A.size();i++){
        cout<<A[i].name+" : "<<A[i].mark<<endl;
    }
}

int randomNum(int k){
    return rand()%k;
}

int main()
{
    int compteur = 0;
    srand(time(0));
    vector<Eleve> group = {};
    for(int i=0;i<student_number;i++){
        Eleve student(randomName(),randomNum(20));
        group.push_back(student);
    }
    compteur = 0;
    sort(group.begin(),group.end(),CompareNom(&compteur));
    cout<< "List sorted regarding students' names with "<<compteur<< " comparaison :"<<endl;
    print(group);
    cout<<"\n"<<endl;
    compteur=0;
    sort(group.begin(),group.end(),CompareNote(&compteur));
    cout<<"List sorted regarding students' marks with " <<compteur<<" comparaison :"<<endl;
    print(group);
    return 0;
}
