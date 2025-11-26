#include <vector>
#include <iostream>
using namespace std;

class Eleve{
    string name;
    int note;
public:
    Eleve(string s,int n);
    string const displayName();
    int const displayNote();
};

class CompareNote{
public:
    bool operator()(Eleve a,Eleve b);
};

class CompareName{
public:
    bool operator()(Eleve a,Eleve b);
};
