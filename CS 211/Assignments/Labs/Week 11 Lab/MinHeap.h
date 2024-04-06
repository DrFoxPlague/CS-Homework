/*-----
  class: MinHeap

  Modified by Andrew Smith, Jonathan Thang, and Dakota Donner
  Last Modified: 2 Nov 2022
-----*/

#ifndef MINHEAP_H
#define MINHEAP_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

const int DEFAULT_CAPACITY = 15;  // For the zero-argument constructor

// We'll set a typedef statement here
// The type T represents the data type stored in the MinHeap.
// it'd be great if you used T instead of int in your code :-)

typedef int T;     // Data type for each key value in a MinHeap

using namespace std;

class MinHeap {
public:

    // Constructors

    MinHeap();
    MinHeap(int capacity);

    // Destructor
    ~MinHeap();

    // Accessors
    int getSize() const;
    int getCapacity() const;
    void printArray() const;

    // Mutators
    bool insertValue(T newValue);
    T removeValue();

 private:
     int heapSize;
     int heapCapacity;
     T *heapArray;

     void swap(int indexA, int indexB);
};

#endif /* MINHEAP_H */
