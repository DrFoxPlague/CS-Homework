/*---
    CS 211 Fall 2022 - Week 11 Lab
    MinHeap in C++

    David C. Tuttle
    Modified by Andrew Smith, Jonathan Thang, and Dakota Donner
    Last Modified: 2 Nov 2022
---*/

//----------------------------------------------------
// File: MinHeap.cpp
// Purpose: Implementation file for a MinHeap class
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;

// Constructors and Destructor

MinHeap::MinHeap() {
    heapCapacity = DEFAULT_CAPACITY;
    heapArray = new T[heapCapacity];
    heapSize = 0;
}

MinHeap::MinHeap(int capacity) {
    heapCapacity = capacity;
    heapArray = new T[heapCapacity];
    heapSize = 0;
}

MinHeap::~MinHeap() {
    delete [] heapArray;
    heapArray = NULL;
}

//--------------------------------------------
// Function: getSize()
// Purpose: accessor for size of MinHeap
// Returns: number of values stored in MinHeap
//--------------------------------------------

int MinHeap::getSize() const {
    return heapSize;
}

//--------------------------------------------
// Function: getCapacity()
// Purpose: accessor for capacity of MinHeap
// Returns: total capacity of MinHeap
//--------------------------------------------

int MinHeap::getCapacity() const {
    return heapCapacity;
}

//--------------------------------------------
// Function: printArray()
// Purpose: prints values stored in MinHeap array
// Returns: nothing
//--------------------------------------------

void MinHeap::printArray() const {
    cout << "Size = " << heapSize << ", Capacity = " << heapCapacity << ", Values are";
    for(int i = 0; i < heapSize; i++)
        cout << " " << heapArray[i];
    cout << endl;
}

//--------------------------------------------
// Function: insertValue()
// Purpose: inserts value in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

bool MinHeap::insertValue(T newValue) {
    if(heapSize == heapCapacity){
        cout << endl << "Error: Heap is already full!" << endl;
        return false;
    }

    heapArray[heapSize] = newValue;
    heapSize++;
    int index = heapSize-1;
    while(index > 0){
        int parentIndex = (index-1)/2;
        if(heapArray[index] >= heapArray[parentIndex])
            return true;
        else {
            int temp = heapArray[index];
            heapArray[index] = heapArray[parentIndex];
            heapArray[parentIndex] = temp;
            index = parentIndex;
        }
    }
    return true;
}

//--------------------------------------------
// Function: removeValue()
// Purpose: prints values stored in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

T MinHeap::removeValue() {
    //There should be more here, sorry!
    return heapArray[0];
}

void MinHeap::swap(int indexA, int indexB) {
    bool swapped = true;
    T temp;
    while(swapped){
        if(heapArray[indexA] < heapArray[indexB]){
            temp = heapArray[indexB];
            heapArray[indexB] = heapArray[indexA];
            heapArray[indexA] = temp;
            indexA = indexB;
            indexB = (indexA - 1) / 2;
        }
        else
            swapped = false;
    }
}
