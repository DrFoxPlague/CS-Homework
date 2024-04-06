/*---
    BSTNode and BST classes
---*/

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

typedef int T;

/*-----
  class: BSTNode

  purpose: To create a BSTNode for use in for a binary tree
  NOTE: All code for the class is in this .h file
  Do NOT alter this class's clode in any way!

  by: David Tuttle
  last modified: 31 Oct 2022
-----*/

class BSTNode {
public:

    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              (optionally) two pointers to "children"
    BSTNode() {
        leftChild = NULL;
        rightChild = NULL;
    }

    BSTNode(T e, BSTNode *l = NULL, BSTNode *r = NULL) {
        el = e;
        leftChild = l;
        rightChild = r;
    }
    
    // Apparently, some compilers don't like specifying the
    // destructor here, whereas MinGW with NetBeans does
    // not care.  Sorry about that!
    // ~BSTNode();
    
    // Accessors
    
    T getEl() {
        return el;
    }
    BSTNode *getLeftChild() {
        return leftChild;
    }
    BSTNode *getRightChild() {
        return rightChild;
    }
    
    // Mutators
    
    void setEl(T newEl) {
        el = newEl;
    }
    void setLeftChild(BSTNode *nodePtr) {
        leftChild = nodePtr;
    }
    void setRightChild(BSTNode *nodePtr) {
        rightChild = nodePtr;
    }
    
private:
    T el;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

/*-----
  class: BST

  purpose: To implement a binary search tree
  using the given BSTNode class

  constructors:
           *   BST creates a new stack object
           *   isEmpty returns TRUE if the tree is empty
	   *   search returns TRUE is value is found in tree
	   *   insert places a node into tree


  by: David Tuttle
  last modified: 31 Oct 2021
-----*/

class BST {
public:
    // Constructor
    BST() {
        // Create an empty binary tree
        // The first insertion will place a Node at the root
        root = NULL;
    }
    
    // Destructor commented out (see BSTNode destructor above)
    // ~BST();

    // Accessors
    bool search(T el) const; 
    bool isLeaf(T el) const;
    BSTNode* getRoot() const;
    bool isEmpty() const;
    void testy();   // DEBUGGING FUNCTION - plz ignore if still here :)

    void preorderTraversal() const;
    void inorderTraversal() const;
    void postorderTraversal() const;
    int countNodes() const;
    int countLeaves() const;
    int treeHeight() const;

    // Mutators
    bool insert(T el);
    bool deleteLeaf(T el);

    void deleteAllNodes();
    bool deleteNode(T el);
    void leftRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);
    void rightRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);
    
private:
    BSTNode *root;

    //--------------------------------------------
    // Function: preorderRecursive(BSTNode*)
    // Purpose: helper function for preorderTraversal()
    // Returns: void
    //--------------------------------------------

    void preorderRecursive(BSTNode *nodePtr) const
    {
        if (nodePtr != NULL)
        {
            cout << nodePtr->getEl() << " ";
            preorderRecursive(nodePtr->getLeftChild());
            preorderRecursive(nodePtr->getRightChild());
        }

        else
            return;
    }

    //--------------------------------------------
    // Function: inorderRecursive(BSTNode*)
    // Purpose: helper function for inorderTraversal()
    // Returns: void
    //--------------------------------------------

    void inorderRecursive(BSTNode *nodePtr) const
    {
        if (nodePtr != NULL)
        {
            inorderRecursive(nodePtr->getLeftChild());
            cout << nodePtr->getEl() << " ";
            inorderRecursive(nodePtr->getRightChild());
        }

        else
            return;
    }

    //--------------------------------------------
    // Function: postorderRecursive(BSTNode*)
    // Purpose: helper function for postorderTraversal()
    // Returns: void
    //--------------------------------------------

    void postorderRecursive(BSTNode *nodePtr) const
    {
        if (nodePtr != NULL)
        {
            postorderRecursive(nodePtr->getLeftChild());
            postorderRecursive(nodePtr->getRightChild());
            cout << nodePtr->getEl() << " ";
        }

        else
            return;
    }
    
    //--------------------------------------------
    // Function: totalRecursive(BSTNode*)
    // Purpose: helper function for countNodes()
    // Returns: int - the total number of nodes
    //--------------------------------------------

    int totalRecursive(BSTNode *nodePtr) const
    {
        if (nodePtr == NULL)
            return 0;

        else
        {
            /*count = totalRecursive(nodePtr->getLeftChild(), (count + 1));
            count = totalRecursive(nodePtr->getRightChild(), (count));
            return count;*/

            return totalRecursive(nodePtr->getLeftChild()) + totalRecursive(nodePtr->getRightChild()) + 1;
        }
    }

    //--------------------------------------------
    // Function: leafRecursive(BSTNode*, int)
    // Purpose: helper function for countLeaves()
    // Returns: int - the total number of leaf nodes
    //--------------------------------------------

    int leafRecursive(BSTNode *nodePtr, int count) const
    {
        if (nodePtr != NULL)
        {
            if (isLeaf(nodePtr->getEl()) == true)
                count++;

            count = leafRecursive(nodePtr->getLeftChild(), count);
            count = leafRecursive(nodePtr->getRightChild(), count);
        }

        return count;
    }

    //--------------------------------------------
    // Function: heightRecursive(BSTNode*)
    // Purpose: helper function for treeHeight()
    // Returns: int - the height of the tree
    //--------------------------------------------

    int heightRecursive(BSTNode *nodePtr) const
    {
        if (nodePtr == NULL)
            return -1;

        return 1 + max((heightRecursive(nodePtr->getLeftChild())), (heightRecursive(nodePtr->getRightChild())));
    }

    //--------------------------------------------
    // Function: delAllRecursive(BSTNode*)
    // Purpose: helper function for deleteAllNodes()
    // Returns: void
    //--------------------------------------------

    void delAllRecursive(BSTNode *nodePtr)
    {
        if (nodePtr == NULL)
            return;

        delAllRecursive(nodePtr->getLeftChild());
        delAllRecursive(nodePtr->getRightChild());
        cout << "Now deleting value: " << nodePtr->getEl() << endl;
        delete nodePtr;
        nodePtr = NULL;
        root = NULL;
    }
};

#endif /* BST_H */

