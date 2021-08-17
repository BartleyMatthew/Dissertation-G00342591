#include <cstddef>
#include <string>
#include <iostream>
#include "Backend.h"
using namespace std;

// node class
class Node
{
public:
    // nodes must have at least t-1 keys and most 2t -1
    // this does not apply to roots
    // we set these bounds with t/minimum degree
  
    int *keys; // array of keys
    string *values; // array of values
    Node** children; // array of pointers for children
    int t; // minimum degree
    int numKey; // number of keys
    bool leaf; // is it a leaf node

    // constructor
    // deg is to distinguish itself from int t
    public: Node(int deg, bool isLeaf);
          void traverseTree();

    // so we can access private members later
    friend class Tree;
};

// tree class
class Tree {
    Tree* root; // pointer to access the route
    int t; // min degree
    // constructor
    // we use this to initialise a tree as an empty tree
    public: Tree(int deg) { root = NULL; t = deg; };
};

// node constructor for node class
Node:: Node(int deg, bool isLeaf) {
    t = deg;
    leaf = isLeaf;

    // sets the max number of keys possible and children
    keys = new int[2 * t - 1];
    children = new Node * [2 * t];

    // set starting number of keys to 0
    numKey = 0;
};


// for traversing through all nodes that derive from this node 
// Node:: to show traverse() belongs to the node class and isn't derived from other classes like tree
void Node::traverseTree(){
    int i;
    for (i = 0; i < numKey; i++) {
        if (leaf == false) {
            // if it isn't a leaf then traverse into it's rubroot child
            children[i]->traverseTree();
        }
        else {
            // if it's a leaf node print it's key
            cout << keys[i] << endl;
        }
    }
    // print last childs key
    if (leaf == false) {
        children[i]->traverseTree();
    }
        
}
