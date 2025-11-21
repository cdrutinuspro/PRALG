#pragma once
#include <vector>

/// Node of a tree containing an integer at each node
class IntTree {
    int data; ///< Node information
    std::vector<IntTree*> sons; ///< Sequence of sons (empty if none)
public:
    IntTree(int d); ///< Create a node with given information
    ~IntTree();     ///< Destruct a node and all its descendants

    int getData() const; ///< Return information of this node
    void setData(int d); ///< Set information of this node

    int nbSons() const; ///< Return the number of sons of this node

    void setSon(int pos, IntTree* newSon); ///< Replace son at pos with newSon
    IntTree* getSon(int pos); ///< Son at pos (left-most son at position 0)
    const IntTree* getSon(int pos) const; ///< See non-const overload

    void addAsLastSon(IntTree* newSon); ///< Add newSon as right-most son
    void removeLastSon(); ///< Remove right-most son of this node
};
