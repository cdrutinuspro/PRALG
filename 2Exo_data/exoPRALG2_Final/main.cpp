// (c) 2019 Pascal Monasse

//#define TEMPLATE // Comment out to use untemplated class
#ifdef TEMPLATE
#include "tree.h"
typedef Tree<int> IntTree;
#else
#include "inttree.h"
#endif

#include <stdexcept>
#include <iostream>
using namespace std;

void errors(IntTree& root) {
    // Errors
    try {
        root.getSon(2);
    } catch(range_error& e) {
        cerr << e.what() << endl;
    }
    try {
        IntTree t(-1);
        root.setSon(2,&t);
    } catch(range_error& e) {
        cerr << e.what() << endl;
    }
    try {
        root.setSon(0,0);
    } catch(invalid_argument& e) {
        cerr << e.what() << endl;
    }
    try {
        root.getSon(0)->addAsLastSon(0);
    } catch(invalid_argument& e) {
        cerr << e.what() << endl;
    }
    try {
        root.getSon(0)->getSon(0)->removeLastSon();
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
    }
#ifdef TEMPLATE
    try {
        root.insertSon(0,0);
    } catch(invalid_argument& e) {
        cerr << e.what() << endl;
    }
    try {
        IntTree t(-1);
        root.insertSon(-1,&t);
    } catch(range_error& e) {
        cerr << e.what() << endl;
    }
    try {
        root.removeSon(2);
    } catch(range_error& e) {
        cerr << e.what() << endl;
    }    
#endif
}

int main() {
    IntTree root(12);
    root.addAsLastSon(new IntTree(8));
    root.getSon(0)->addAsLastSon(new IntTree(4));
    root.getSon(0)->addAsLastSon(new IntTree(9));
    root.addAsLastSon(new IntTree(23));
    root.getSon(1)->addAsLastSon(new IntTree(17));
    root.getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));
    root.display("* ");

    errors(root);

#ifdef TEMPLATE
    root.displayDepthIn(); cout << endl;
    root.displayDepthOut();
    root.displayBreadth();

    cout << "Min depth: " << root.minDepth() << endl;
    cout << "Max depth: " << root.maxDepth() << endl;
#endif
    
    return 0;
}

// Q2.1: parcours en profondeur
// Q4.2: non, template
// Q4.3: non, erreur independantes du type
// Q5.2: en profondeur, pas d'allocation memoire
// Q5.3: en largeur, on s'arrete des qu'on atteint une feuille

