//--------------------------------------------------
//  class: doublyLinkedList
//
//  purpose: To implement a Double Linked List object
//
//  member functions: has 3 member functions:
//           *   doublyLinkedList creates a DLL object
//           *   addToDLLTail adds a node to the DLL at the tail
//	   *   deleteFromDLLTail deletes a node from the DLL at the tail
//
//  by: David Tuttle
//  last modified: 2014-09-22
//  modified by: Dakota Donner
//
//--------------------------------------------------

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

//--------------------------------------------------
//  class: DLLNode
//
//  purpose: To create a data element for a Doubly Linked List
//
//  by: David Tuttle
//  last modified: 2014-09-18
//
//--------------------------------------------------
class DLLNode {
public:
    DLLNode();
    DLLNode(const double el, DLLNode *n = 0, DLLNode *p = 0) {
        info = el;      // Place value into new node
        next = n;       // Set link to next node in list
        prev = p;       // Set link to previous node in list
    };

    double info;
    DLLNode *next, *prev;
};

class doublyLinkedList {
public:
    doublyLinkedList();           // Class constructor
    void addToDLLTail(double el); // Add a DLLNode with value el to tail of DLL
    double deleteFromDLLTail();   // Remove a DLLNode from tail of DLL
    void addToDLLHead(double el); // Add a DLLNode with value el to head of DLL
    double deleteFromDLLHead();   // Remove a DLLNode from head of DLL

private:
    DLLNode *head, *tail;
};

#endif
