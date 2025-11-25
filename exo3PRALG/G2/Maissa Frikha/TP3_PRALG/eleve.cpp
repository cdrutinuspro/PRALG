#include "eleve.h"
#include <cstdlib>
#include <iostream>

Eleve :: Eleve(string name0, int note0){
    name = name0;
    note = note0;
}


void afficherEleves( const vector<Eleve>& vec) {
    for (EleveConstIterator it = vec.begin(); it != vec.end(); ++it){
        cout << it -> getName() << "-" << it -> getNote()<< endl;
    }
}
