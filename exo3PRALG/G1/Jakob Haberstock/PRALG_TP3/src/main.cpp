#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Eleve.h"
using namespace std;

void printIntVector(vector<int> vec) {
    for (int i=0; i<vec.size(); i++) 
        cout << vec[i] << " ";
    cout << endl;
}
void printEleveVector(vector<Eleve> vec) {
    for (int i=0; i<vec.size(); i++){
        Eleve eleve = vec[i];
        cout << i << ": " << eleve.getStringRep() << "\n";
    } 
}


random_device rd;                 
mt19937 gen(rd());                
uniform_int_distribution<> distLetter(0, 25); 
uniform_int_distribution<> distLength(1, 10); 
uniform_int_distribution<> distNotes(0, 20); 
string createRandomName() {
    // first big letter: 
    string name = "";
    name += 'A' + distLetter(gen);

    int lengthOfNameAfterFirstLetter = distLength(gen);
    for (int i=0; i < lengthOfNameAfterFirstLetter; ++i) 
        name += ('a' + distLetter(gen));
    
    return name;
}
int createRandomNote() {
    return distNotes(gen);
}
vector<Eleve> getEleveVector(int numberOfElements = 10) {
    vector<Eleve> vec; 
    string name;
    int note;
    for (int i=0; i < numberOfElements; ++i) {
        name = createRandomName();
        note = createRandomNote();
        vec.push_back(Eleve(name, note));
    }
    return vec;
}

void testFcn1() {
    Eleve me("Bob", 7);
    // me.setName("HI");
    // me.setNote(8);
    cout << "Name: " << me.getName() << endl << "Note: " << me.getNote() << endl;
}
void testFcn2() {
    vector<Eleve> vec = getEleveVector(100);
    printEleveVector(vec);
}
void testFcn3() {
    Eleve el1 = Eleve("Albert", 18);
    Eleve el2 = Eleve("Berta", 16);
    Eleve el3("Christoph", 14);


    cout << el1.getStringRep() << endl;
    cout << el2.getStringRep() << endl;
    cout << el3.getStringRep() << endl;


    cout << "\n\nCOMPARASON BY NAME: " << endl;
    CompareName comparatorName;
    cout << "Is el1(" + el1.getStringRep() + ") < el2("+ el2.getStringRep() + ")? => ";
    cout << comparatorName(el1, el2) << endl;
    cout << "Is el2(" + el2.getStringRep() + ") < el1("+ el1.getStringRep() + ")? => ";
    cout << comparatorName(el2, el1) << endl;

    cout << "Is el2(" + el2.getStringRep() + ") < el3("+ el3.getStringRep() + ")? => ";
    cout << comparatorName(el2, el3) << endl;
    cout << "Is el3(" + el3.getStringRep() + ") < el2("+ el2.getStringRep() + ")? => ";
    cout << comparatorName(el3, el2) << endl;

    cout << "Is el1(" + el1.getStringRep() + ") < el3("+ el3.getStringRep() + ")? => ";
    cout << comparatorName(el1, el3) << endl;
    cout << "Is el3(" + el3.getStringRep() + ") < el1("+ el1.getStringRep() + ")? => ";
    cout << comparatorName(el3, el1) << endl;

    cout << "\n\nCOMPARASON BY NOTE: " << endl;
    CompareNote comparatorNote;
    cout << "Is el1(" + el1.getStringRep() + ") < el2("+ el2.getStringRep() + ")? => ";
    cout << comparatorNote(el1, el2) << endl;
    cout << "Is el2(" + el2.getStringRep() + ") < el1("+ el1.getStringRep() + ")? => ";
    cout << comparatorNote(el2, el1) << endl;

    cout << "Is el2(" + el2.getStringRep() + ") < el3("+ el3.getStringRep() + ")? => ";
    cout << comparatorNote(el2, el3) << endl;
    cout << "Is el3(" + el3.getStringRep() + ") < el2("+ el2.getStringRep() + ")? => ";
    cout << comparatorNote(el3, el2) << endl;

    cout << "Is el1(" + el1.getStringRep() + ") < el3("+ el3.getStringRep() + ")? => ";
    cout << comparatorNote(el1, el3) << endl;
    cout << "Is el3(" + el3.getStringRep() + ") < el1("+ el1.getStringRep() + ")? => ";
    cout << comparatorNote(el3, el1) << endl;


}
void testFcn4() {}

void testFcn5() {
    CompareNote comparatorName;
    cout << "Value of ptr: " <<  *comparatorName.ptr << endl;

    Eleve el1("Anton", 1);
    Eleve el2("Beate", 5);

    cout << "Is el1(" + el1.getStringRep() + ") < el2("+ el2.getStringRep() + ")? => ";
    cout << comparatorName(el1, el2) << endl;

    cout << "Value of ptr: " <<  *comparatorName.ptr << endl;
}
void testFcn6() {
}

void doGivenTask() {
    CompareName comparatorName;
    int comparatorCounterName = 0;
    comparatorName.ptr = &comparatorCounterName;

    CompareNote comparatorNote;
    int comparatorCounterNote = 0;
    comparatorNote.ptr = &comparatorCounterNote;

    vector<Eleve> vec = getEleveVector(10);

    cout << "Printing original vector: " << endl;
    printEleveVector(vec);
    cout << "comparatorCounterName: " << comparatorCounterName << " | comparatorCounterNote: " << comparatorCounterNote << endl << endl;

    sort(vec.begin(), vec.end(), comparatorName); 
    cout << "Printing vector sorted by NAME: " << endl;
    printEleveVector(vec);
    cout << "comparatorCounterName: " << comparatorCounterName << " | comparatorCounterNote: " << comparatorCounterNote << endl << endl;

    sort(vec.begin(), vec.end(), comparatorNote); 
    reverse(vec.begin(), vec.end()); // reverse because my 'comparatorNote' sorts in ascending and not descending order
    cout << "Printing vector sorted by NOTE: " << endl;
    printEleveVector(vec);
    cout << "comparatorCounterName: " << comparatorCounterName << " | comparatorCounterNote: " << comparatorCounterNote << endl << endl;
}

int main() {
    doGivenTask();
}
