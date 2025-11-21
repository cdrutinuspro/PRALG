#pragma once
#include <vector>
#include <queue>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

/// Node of a tree containing an integer at each node
template <typename T>
class Tree {
    T data; ///< Node information
    std::vector<Tree<T>*> sons; ///< Sequence of sons (empty if none)
public:
    Tree(int d); ///< Create a node with given information
    ~Tree();     ///< Destruct a node and all its descendants

    int getData() const; ///< Return information of this node
    void setData(int d); ///< Set information of this node

    int nbSons() const; ///< Return the number of sons of this node

    void setSon(int pos, Tree<T>* newSon); ///< Replace son at pos with newSon
    Tree<T>* getSon(int pos); ///< Son at pos (left-most son at position 0)
    const Tree<T>* getSon(int pos) const; ///< See non-const overload

    void addAsLastSon(Tree<T>* newSon); ///< Add newSon as right-most son
    void removeLastSon(); ///< Remove right-most son of this node

    void display(std::string prefix="", std::string indent="  ") const;

    void insertSon(int pos, Tree<T>* son); ///< Insert extra son at \a pos
    void removeSon(int pos);               ///< Remove son at \a pos

    void displayDepthIn(std::string prefix="", std::string indent="  ") const;
    void displayDepthOut(std::string prefix="", std::string indent="  ") const;
    void displayBreadth() const;

    int minDepth() const;
    int maxDepth() const;
};

template <typename T>
Tree<T>::Tree(int d) {
    data=d;
}

template <typename T>
Tree<T>::~Tree() {
    for(typename std::vector<Tree<T>*>::iterator it=sons.begin();
        it!=sons.end(); ++it)
        delete *it;
}

template <typename T>
int Tree<T>::getData() const {
    return data;
}

template <typename T>
void Tree<T>::setData(int d) {
    data=d;
}

template <typename T>
int Tree<T>::nbSons() const {
    return sons.size();
}

/// @throws invalid_argument in case \a newSon is the null pointer.
/// @throws range_error in case \a pos is not a valid index.
template <typename T>
void Tree<T>::setSon(int pos, Tree<T>* newSon) {
    if(! newSon) throw invalid_argument("Tree::setSon: newSon=0");
    if(pos<0||nbSons()<=pos) throw range_error("Tree::setSon: invalid pos");
    delete sons[pos];
    sons[pos] = newSon;
}

/// @throws range_error in case \a pos is not a valid index.
template <typename T>
Tree<T>* Tree<T>::getSon(int pos) {
    if(pos<0||nbSons()<=pos) throw range_error("Tree::getSon: invalid pos");
    return sons.at(pos);
}

/// @throws range_error in case \a pos is not a valid index.
template <typename T>
const Tree<T>* Tree<T>::getSon(int pos) const {
    if(pos<0||nbSons()<=pos) throw range_error("Tree::getSon: invalid pos");
    return sons.at(pos);
}

template <typename T>
void Tree<T>::addAsLastSon(Tree<T>* newSon) {
    if(! newSon) throw invalid_argument("Tree::addAsLastSon: newSon=0");
    sons.push_back(newSon);
}

/// @throws runtime_error in case \a pos is not a valid index.
template <typename T>
void Tree<T>::removeLastSon() {
    if(sons.empty()) throw runtime_error("Tree::removeLastSon: no son");
    delete sons.back();
    sons.pop_back();
}

/// Display depth first. Each element preceded by \a prefix and by
/// (depth times \a indent).
template <typename T>
void Tree<T>::display(string prefix, string indent) const {
    cout << prefix << data << endl;
    prefix += indent;
    for(typename std::vector<Tree<T>*>::const_iterator it=sons.begin();
        it!=sons.end(); ++it)
        (*it)->display(prefix,indent);
}

template <typename T>
void Tree<T>::insertSon(int pos, Tree<T>* son) {
    if(! son) throw invalid_argument("Tree::insertSon: son=0");
    if(pos<0||nbSons()<pos) throw range_error("Tree::insertSon: invalid pos");
    sons.insert(sons.begin()+pos, son);
}

template <typename T>
void Tree<T>::removeSon(int pos) {
    if(pos<0||nbSons()<=pos) throw range_error("Tree::removeSon: invalid pos");
    delete sons.at(pos);
    sons.erase(sons.begin()+pos);
}

template <typename T>
void Tree<T>::displayDepthIn(std::string prefix, std::string indent) const {
    display(prefix,indent);
}

template <typename T>
void Tree<T>::displayDepthOut(std::string prefix, std::string indent) const {
    for(typename std::vector<Tree<T>*>::const_iterator it=sons.begin();
        it!=sons.end(); ++it)
        (*it)->displayDepthOut(prefix+indent,indent);
    cout << prefix << data << endl;
}

template <typename T>
void Tree<T>::displayBreadth() const {
    std::queue<const Tree<T>*> fifo;
    fifo.push(this);
    while(! fifo.empty()) {
        const Tree<T>* node=fifo.front();
        fifo.pop();
        cout << node->data << " ";
        for(typename std::vector<Tree<T>*>::const_iterator it=
                node->sons.begin();
            it!=node->sons.end(); ++it)
            fifo.push(*it);
    }
    cout << endl;
}

template <typename T>
int Tree<T>::minDepth() const {
    std::queue<const Tree<T>*> fifo, nextFifo;
    fifo.push(this);
    int d=1;
    while(true) {
        const Tree<T>* node=fifo.front();
        fifo.pop();
        if(node->nbSons()==0)
            return d;
        for(typename std::vector<Tree<T>*>::const_iterator it=
                node->sons.begin();
            it!=node->sons.end(); ++it)
            nextFifo.push(*it);
        if(fifo.empty()) { ++d; swap(fifo,nextFifo); }
    }
    return d; // Should never reach here
}

template <typename T>
int Tree<T>::maxDepth() const {
    int d=0;
    for(typename std::vector<Tree<T>*>::const_iterator it=sons.begin();
        it!=sons.end(); ++it) {
        int dson = (*it)->maxDepth();
        if(d<dson) d=dson;
    }
    return d+1;
}
