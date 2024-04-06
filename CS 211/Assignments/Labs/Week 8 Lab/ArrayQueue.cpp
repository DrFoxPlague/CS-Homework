// CS 211 Fall 2022 - Week 08 Lab
// Andrew Smith and Dakota Donner

//---------------------------------------------------------------
// File: ArrayQueue.cpp
// Purpose: Implementation file for a queue
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayQueue.h"

using namespace std;

//--------------------------------------------
// Function: ArrayQueue()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayQueue::ArrayQueue() {
    queueArray = new T[QUEUE_SIZE];
    frontIndex = 0;
    backIndex = 0;
    queueEmpty = true;
    queueFull = false;
}

//--------------------------------------------
// Function: ~ArrayQueue()
// Purpose: Class destructor
// Returns: void
//--------------------------------------------

ArrayQueue::~ArrayQueue() {
    delete [] queueArray;
}

//--------------------------------------------
// Function: isFull()
// Purpose: Returns true is queue is full
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isFull() {
        return queueFull;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Returns true if queue is empty
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isEmpty() {
    return queueEmpty;
}

//--------------------------------------------
// Function: firstEl()
// Purpose: Returns element at head of queue
// Side Effects: None
//--------------------------------------------

T ArrayQueue::firstEl() {
    if (isEmpty())
    {
        return -99999;
    }

    return queueArray[frontIndex];
    
}

//--------------------------------------------
// Function: clearQueue()
// Purpose: Removes all items from the queue
// Side Effects: resets queue to empty
//--------------------------------------------

void ArrayQueue::clearQueue() {
    if (isEmpty())
    {
        cout << "ALREADY EMPTY!" << endl;
    }

    else
    {
        frontIndex = 0;
        backIndex = 0;
        queueEmpty = true;
        queueFull = false;
    }
}

//--------------------------------------------
// Function: enQueue(int el)
// Purpose: Returns true if element successfully added
// Side Effects: Adds element to queue
//--------------------------------------------

bool ArrayQueue::enQueue(int el) {
    if (isFull())
    {
        cout << "QUEUE FULL!" << endl;
        return false;
    }

    else if (isEmpty())
    {
        queueEmpty = false;
        backIndex = frontIndex - 1;
    }

    backIndex = ((backIndex + 1 + QUEUE_SIZE) % QUEUE_SIZE);
    queueArray[backIndex] = el;
    
    int difference = backIndex - frontIndex;

    if((difference + QUEUE_SIZE) % QUEUE_SIZE == QUEUE_SIZE - 1)
        queueFull = true;

    return true;
}

//--------------------------------------------
// Function: deQueue()
// Purpose: Returns element at front of queue
// Side Effects: Removes element from queue
//--------------------------------------------

T ArrayQueue::deQueue() {
    if (isEmpty())
    {
        return -99999;
    }
    if (isFull())
        queueFull = false;

    T el = queueArray[frontIndex];

    if((frontIndex == backIndex))
    {
        queueEmpty = true;
        frontIndex = 0;
        backIndex = 0;
    }
    else
        frontIndex = ((frontIndex + 1 + QUEUE_SIZE) % QUEUE_SIZE);
    return el;
}

//--------------------------------------------
// Function: printArray()
// Purpose: Private method prints array values
// Returns: void
//--------------------------------------------

void ArrayQueue::printArray() {
    cout << "*** Contents of array ***" << endl;
    cout << "Front at index " << frontIndex
         << ", Back at index " << backIndex << endl;
    for (int i=0; i<QUEUE_SIZE; i++) {
        cout << i << ":" << queueArray[i] << " ";
    }
    cout << endl;
    cout << "*************************" << endl;
}

