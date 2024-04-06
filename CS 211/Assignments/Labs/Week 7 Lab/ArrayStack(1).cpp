/*
# CS 211 Fall 2022 - Week 07 Lab
# Andrew Smith and Dakota Donner
*/


//---------------------------------------------------------------
// File: ArrayStack.cpp
// Purpose: Implementation file for a demonstration of a stack
//          implemented as an array.    Data type: Double
//
// Modified by David C. Tuttle on 03 Oct 2022
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <vector>
#include "ArrayStack.h"

//--------------------------------------------
// Function: ArrayStack()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayStack::ArrayStack() {
    // top is the index of the array where the top
    // of the stack is; a value of -1 means the
    // stack is empty
    top = -1;
    theStack.resize(10);
    currSize = theStack.size();
}

//--------------------------------------------
// Function: clearStack()
// Purpose: Remove all items from the stack
// Returns: void
//--------------------------------------------

void ArrayStack::clearStack() {
    top = -1; // Reset count to start over
    theStack.resize(10);    // NOTE: There's no need to reset
    currSize = theStack.size();          // array values!  Just reset index
}

//--------------------------------------------
// Function: push()
// Purpose: Push an item onto the stack.
// Returns: true if push was successful
//          or false if the push failed.
//--------------------------------------------

bool ArrayStack::push(T el) {
    // Check to see if the stack if full
        // Increment array index of top of stack
        top++;
        // Add the item to the stack
        theStack[top] = el;
        return true;
}

//--------------------------------------------
// Function: pop()
// Purpose: Pop an item from the Stack.
// Returns: value of item popped if pop was successful
//  or -99999.0 if the pop failed (stack empty)
//--------------------------------------------

T ArrayStack::pop() {
    T el;

    // Check for empty stack
    if (isEmpty()) return ERROR_VALUE;
    else {
        el = theStack[top]; // Get value to return
        top--;     // Decrement top index
        return el; // Return popped value
    }
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the stack is empty
// Returns: true if empty, otherwise false
//--------------------------------------------

bool ArrayStack::isEmpty() {
    // top value is -1 if the stack is empty
    return (top == -1);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the stack is full
// Returns: true if full, otherwise false
//--------------------------------------------

int ArrayStack::getSize() {
    return theStack.size();
}

void ArrayStack::setSize(int newSize) {
    if (theStack.size() < newSize)
        theStack.resize(newSize);
}