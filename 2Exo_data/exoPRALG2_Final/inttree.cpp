#include "inttree.h"
#include <stdexcept>
#include <iostream>
using namespace std;

IntTree::IntTree(int d) {
    data=d;
}

IntTree::~IntTree() {
    for(std::vector<IntTree*>::iterator it=sons.begin(); it!=sons.end(); ++it)
        delete *it;
}

int IntTree::getData() const {
    return data;
}

void IntTree::setData(int d) {
    data=d;
}

int IntTree::nbSons() const {
    return sons.size();
}

/// @throws invalid_argument in case \a newSon is the null pointer.
/// @throws range_error in case \a pos is not a valid index.
void IntTree::setSon(int pos, IntTree* newSon) {
    if(! newSon) throw invalid_argument("IntTree::setSon: newSon=0");
    if(pos<0||nbSons()<=pos) throw range_error("IntTree::setSon: invalid pos");
    delete sons[pos];
    sons[pos] = newSon;
}

/// @throws range_error in case \a pos is not a valid index.
IntTree* IntTree::getSon(int pos) {
    if(pos<0||nbSons()<=pos) throw range_error("IntTree::getSon: invalid pos");
    return sons.at(pos);
}

/// @throws range_error in case \a pos is not a valid index.
const IntTree* IntTree::getSon(int pos) const {
    if(pos<0||nbSons()<=pos) throw range_error("IntTree::getSon: invalid pos");
    return sons.at(pos);
}

/// @throws invalid_argument in case \a newSon is the null pointer.
void IntTree::addAsLastSon(IntTree* newSon) {
    if(! newSon) throw invalid_argument("IntTree::addAsLastSon: newSon=0");
    sons.push_back(newSon);
}

/// @throws runtime_error in case \a pos is not a valid index.
void IntTree::removeLastSon() {
    if(sons.empty()) throw runtime_error("IntTree::removeLastSon: no son");
    delete sons.back();
    sons.pop_back();
}

/// Display depth first. Each element preceded by \a prefix and by
/// (depth times \a indent).
void IntTree::display(string prefix, string indent) const {
    cout << prefix << data << endl;
    prefix += indent;
    for(std::vector<IntTree*>::const_iterator it=sons.begin();
        it!=sons.end(); ++it)
        (*it)->display(prefix,indent);
}
