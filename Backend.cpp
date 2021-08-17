#include <cstddef>
#include <string>
#include <iostream>
#include "Backend.h"
using namespace std;

class SearchTree
{
public:
    int Key;
    string Value;
    SearchTree* Left;
    SearchTree* Right;
    SearchTree* Parent;
    SearchTree* Root;
};

SearchTree* root;

SearchTree* createKeyVal(SearchTree * node,int key, string value)
{
    if (node == NULL)
    {
        node = new SearchTree;
        node->Key = key;
        node->Value = value;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
        node->Root = NULL;
    }
    // greater than node's key go to right subtree
    else if (node->Key < key)
    {
        node->Right = createKeyVal(node->Right, key, value);
        node->Right->Parent = node;
    }
    // smaller than node's key go to left 
    else
    {
        node->Left = createKeyVal(node->Left, key, value);
        node->Left->Parent = node;
    }
    return node;
}

void TraverseSearchTree(SearchTree* node)
{
    // exit if no node
    if (node == NULL)
        return;

    // go to smallest key
    TraverseSearchTree(node->Left);

    // Print the key
    cout << node->Key << endl;
    cout << node->Value << endl;

    // go to largest key
    TraverseSearchTree(node->Right);
}

void create(int key,string value)
{
    root = createKeyVal(root,key, value);
}

void TraverseSearchTree()
{
    TraverseSearchTree(root);
    cout << endl;
}