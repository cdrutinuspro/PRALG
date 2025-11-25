#include "eleve.h"
#include <ctime>
#include <iostream>
#include <algorithm>

void DisplayVector( const vector<Eleve> & v){
    vector<Eleve>::const_iterator it=v.begin();
    for (; it!=v.end();it++){
        cout <<"Name:"<<" "<< it->Name<< "    "<<"Grade:"<<" " <<it->grade<<endl;
    }
}

int main()
{   srand(time(nullptr));
    vector <Eleve> v;
    for (int i=0;i<10;i++){
        Eleve x ;
        v.push_back(x);
    }
    int p=0;
    int q=0;
    CompareNote compgrade (&p);
    CompareNom compname(&q);
    std::sort(v.begin(),v.end(),compgrade);
    cout<<" Sorted by Grade"<<endl;
    DisplayVector(v);
    cout <<*(compgrade.ptr)<<endl;
    std::sort(v.begin(),v.end(),compname);
    cout<<"Sorted by Alphabetical order"<<endl;
    DisplayVector(v);
    cout <<*(compname.ptr)<<endl;
    return 0;
}
