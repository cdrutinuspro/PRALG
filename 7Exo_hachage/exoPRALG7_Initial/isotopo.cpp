// Student: 

#include <iostream>
#include "town.h"

using namespace std;
    
// Study French isotoponyms
int main(int argc, char* argv[]) {
    string townFile = argc>1? argv[1]: srcPath "/villes.txt";
    vector<Town> towns = Town::read_towns(townFile);
    return 0;
}
