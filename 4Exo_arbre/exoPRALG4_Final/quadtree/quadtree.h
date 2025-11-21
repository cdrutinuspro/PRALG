/***************************************************************************
* Basic datatypes to construct a quadtree
*
* Author: Renaud Marlet (c) 2011-2018
***************************************************************************/

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

/*--------------------------------------------------------------------------*
* The quadrant directions
*--------------------------------------------------------------------------*/

// The 4 quadrant directions
const int NW = 0; // North-West
const int NE = 1; // North-East
const int SE = 2; // South-East
const int SW = 3; // South-West
// The number of directions
const int nQuadDir = 4;

// Forward declarations (so that the class names can be used in QuadTree)
template <typename T> class QuadLeaf; // The type of a QuadTree leaf
template <typename T> class QuadNode; // The type of a QuadTree node

/*--------------------------------------------------------------------------*
* Abstract class for quadtrees, whose leaves contain a value of type T
* 
* Note that this class cannot be instantiated.  Only the QuadLeaf and QuadNode
* classes can be instantiated.  However, generic methods can be defined
* at the level of this superclass.
*--------------------------------------------------------------------------*/
template <typename T>
class QuadTree {
public:
    // Flag to indicate whether leaves should be excluded from deletion
    // when a (recursive) destruction is invoked on a tree
    static bool protect_leaves_from_destruction;
public:
    // Constructors are defined in each subclass

    // Destruct this node or leaf and, recursively, subtrees
    // Note: deletion of quad-dag (quadtree with node sharing) is not supported
    virtual ~QuadTree() {}

    // Tell if this quadtree is a leaf
    virtual bool isLeaf() const = 0; // This makes QuadTree an abstract class

    // Tell if this quadtree is a node
    bool isNode() const { return !isLeaf();}

    // Return the number of leaves in this qtree
    virtual int nLeaves() const = 0;

    // Return the number of nodes in this qtree (excluding leaves)
    virtual int nNodes() const = 0;

    // Return the number of (sub)trees in this qtree (nodes and leaves)
    virtual int nTrees() const = 0;

    ///// QuadLeaf methods

    // Return the value of this QuadTree 
    // Throw domain_error if not a QuadLeaf
    virtual T value() const = 0;

    // Return a reference to the value of this QuadLeaf (for assignments)
    // Throw domain_error if not a QuadLeaf
    virtual T& value() = 0;

    ///// QuadNode methods

    // Return the child of this quadtree in direction d
    // Throw domain_error if not a QuadNode
    virtual const QuadTree<T>* child(int d) const = 0;

    // Return a reference to the child of this quadtree in direction d
    // Throw domain_error if not a QuadNode
    virtual QuadTree<T>*& child(int d) = 0;
};

// Flag to indicate whether leaves should be excluded from deletion
// when a (recursive) destruction is invoke on a tree -- defaults to false
template <typename T>
bool QuadTree<T>::protect_leaves_from_destruction = false;


/*--------------------------------------------------------------------------*
* A leaf of a quadtree, containing a value of type T
*--------------------------------------------------------------------------*/
template <typename T>
class QuadLeaf : public QuadTree<T> {
    T val; // The value contained in this leaf
public:
    // Tell if this quadtree is a leaf
    bool isLeaf() const { return true; }

    // Construct a QuadLeaf with the given value
    QuadLeaf(T value) : val(value) {}

    // Return the number of leaves in this qtree
    int nLeaves() const { return 1; }

    // Return the number of nodes in this qtree (excluding leaves)
    int nNodes() const { return 0; }

    // Return the number of (sub)trees in this qtree (nodes and leaves)
    int nTrees() const { return 1; }

    ///// QuadLeaf methods

    // Return the value of this QuadLeaf
    T value() const { return val; }

    // Return a reference to the value of this QuadLeaf (for assignments)
    T& value() { return val; }

    ///// QuadNode methods

    // Supposed to return the child of this quadtree in direction d
    // But throw domain_error as not a QuadNode
    QuadTree<T>* child(int d) const {
        throw new std::domain_error("Not a QuadNode"); }

    // Return a reference to the child of this quadtree in direction d
    // But throw domain_error as not a QuadNode
    QuadTree<T>*& child(int d) {
        throw new std::domain_error("Not a QuadNode"); }
};

/*--------------------------------------------------------------------------*
* A branching node of a quadtree, whose leaves contain a value of type T
*--------------------------------------------------------------------------*/
template <typename T>
class QuadNode : public QuadTree<T> {
    QuadTree<T>* children[nQuadDir]; // Children for the 4 quadrant directions
public:
    // Tell if this quadtree is a leaf
    bool isLeaf() const { return false; }

    // Construct a new branching node given an array of 4 quadtrees 
    QuadNode(QuadTree<T>* qtrees[nQuadDir]) {
        for (int i = 0; i < nQuadDir; i++) children[i] = qtrees[i];
    }

    // Construct a new branching node with empty (null) children
    QuadNode() {
        for (int i = 0; i < nQuadDir; i++) children[i] = 0;
    }

    // Construct a new branching node given 4 children
    QuadNode(QuadTree<T>* child0,
             QuadTree<T>* child1,
             QuadTree<T>* child2,
             QuadTree<T>* child3) {
        children[0] = child0; children[1] = child1;
        children[2] = child2; children[3] = child3;
    }

    // Destruct this QuadNode and, recursively, subtrees
    // Note: deletion of quad-dag (quadtree with node sharing) is not supported
    ~QuadNode() {
        // For each direction
        for (int i=0; i<nQuadDir; i++)
            if(children[i] && !(children[i]->isLeaf() &&
                                QuadTree<T>::protect_leaves_from_destruction))
                delete children[i];
    }

    // Return the number of leaves in this qtree
    int nLeaves() const {
        int n = 0;
        for(int i=0; i<nQuadDir; i++)
            if(children[i])
                n += children[i]->nLeaves();
        return n;
    }

    // Return the number of nodes in this qtree (excluding leaves)
    int nNodes() const {
        int n = 1;
        for(int i=0; i<nQuadDir; i++)
            if (children[i])
                n += children[i]->nNodes();
        return n;
    }

    // Return the number of (sub)trees in this qtree (nodes and leaves)
    int nTrees() const {
        int n = 1;
        for(int i=0; i<nQuadDir; i++)
            if(children[i])
                n += children[i]->nTrees();
        return n;
    }

    ///// QuadLeaf methods

    // Supposed to return the value of this QuadTree 
    // But throw a domain_error as it is not a QuadLeaf
    T value() const { throw new std::domain_error("Not a QuadLeaf"); }

    // Supposed to return a reference to the value of this QuadTree
    // But throw a domain_error as it is not a QuadLeaf
    T& value() { throw new std::domain_error("Not a QuadLeaf"); }

    ///// QuadNode methods

    // Return the child of this quadtree in direction d 
    const QuadTree<T>* child(int d) const {
        if(!(0 <= d && d < nQuadDir)) {
            std::ostringstream oss; oss << d;
            throw new std::out_of_range("Not a valid direction: "+oss.str());
        }
        return children[d];
    }

    // Return a reference to the child of this quadtree in direction d
    QuadTree<T>*& child(int d) {
        if (!(0 <= d && d < nQuadDir)) {
            std::ostringstream oss; oss << d;
            throw std::out_of_range("Not a valid direction: "+oss.str());
        }
        return children[d];
    }
};

// For debugging

/// Display a quadtree on standard output
template <typename T>
void display(QuadTree<T>* qt, std::string prefix = "", void(*prt)(T) = 0){
    if(! qt) // Null tree
        std::cout << prefix << " ." << std::endl;
    else {
        if (qt->isLeaf()) { // If tree is leaf
            std::cout << prefix << " = ";
            if (prt)
                (*prt)(qt->value());
            else
                std::cout << (double)qt->value();
            std::cout << std::endl;
        } else { // If tree is a branch node
            const std::string dirName[] = {"NW", "NE", "SE", "SW"};
            for (int d = 0; d < nQuadDir; d++)
                display(qt->child(d), prefix+"-"+dirName[d], prt);
        }
    }
}
