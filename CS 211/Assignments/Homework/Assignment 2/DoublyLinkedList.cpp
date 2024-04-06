//---------------------------------------------------------------
// File: doublyLinkedList.cpp
// Purpose: Implementation file for a doubly-linked list
//          Element type: Double
//
// Written by David Tuttle, 2014-09-18
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <cstdlib>
#include "doublyLinkedList.h"

//--------------------------------------------
// Function: doublyLinkedList()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

doublyLinkedList::doublyLinkedList() {
  head = 0;
  tail = 0;
}

//--------------------------------------------
// Function: addToDLLTail(double)
// Purpose: Add DLLNode with double value to tail of DLL
// Returns: void
//--------------------------------------------

void doublyLinkedList::addToDLLTail(double el) {
    if (tail != 0) {                      // If DLL is non-empty
          tail = new DLLNode(el,0,tail);  // Allocate new DLLNode
          tail->prev->next = tail;        // Link new node to tail of DLL
    }
    else {                                // If DLL is empty
        head = new DLLNode(el);           // Allocate new DLLNode
        tail = head;                      // Node is first in the DLL, so it
                                          // is both head and tail
    }
}

//--------------------------------------------
// Function: deleteFromDLLTail()
// Purpose: Delete DLLNode from tail of DLL
// Returns: void
//--------------------------------------------

double doublyLinkedList::deleteFromDLLTail() {
    double el = tail->info;               // Get value of node to be deleted

    if (tail == 0)
        throw ("EMPTY");                   // Return an error condition
   
    else if (head == tail) {              // If only DLLNode in the DLL
        delete head;                      // Deallocate DLLNode
        head = 0;                         // Set both head and tail to values for
        tail = 0;                         // a DLL with no nodes
    }

    else {                                // If more than one DLLNode in DLL
        tail = tail->prev;                // Move tail to previous DLLNode
        delete tail->next;                // Deallocate DLLNode
        tail->next = 0;                   // Set next of new last DLLNode to 0
    }
    return el;                            // Return value in deleted DLLNode
}

/*----
  signature: addToDLLHead: double -> void

  purpose: expects a double, adds that via a 
           DLL Node to the head of the
           DoublyLinkedList instance, 
           and returns nothing.
----*/

void doublyLinkedList::addToDLLHead(double el)
{
    if (head != 0)
    {
        head = new DLLNode(el,head,0);
        head->next->prev = head;
    }

    else
    {
        head = new DLLNode(el);
        tail = head; 
    }
}

/*----
  signature: deleteFromDLLHead: void -> double

  purpose: expects nothing, deletes the DLL Node
           at the head of the DoublyLinkedList
           instance, and returns the value of
           the deleted node.
----*/

double doublyLinkedList::deleteFromDLLHead()
{
    double el = head->info;               

    if (head == 0)
        throw ("EMPTY");                  
   
    else if (tail == head) 
    {
        delete head;
        head = 0;
        tail = 0;
    }

    else 
    {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }

    return el;
}