// CS 211 Fall 2022 - Week 08 Lab
// Andrew Smith and Dakota Donner

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

/*-----
  class: ArrayQueue

  purpose: To implement a queue using an Array

  constructors: has 1 method:
           *   Queue is a constructor for a new queue object

  getters: isFull() - returns true if queue is empty
           isEmpty() - return true if queue is empty
           firstEl() - return element at front of queue

  setters: clearQueue() - clears queue
           enQueue(int) - adds element to back of queue
           deQueue() - removes element from front of queue

  by: David Tuttle
  last modified: 11 Oct 2022
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

typedef int T;

class ArrayQueue {
public:

    const int QUEUE_SIZE = 10;

    // CONSTRUCTOR
    ArrayQueue();

    // DESTRUCTOR
    ~ArrayQueue();

    // ACCESSORS
    bool isFull();
    bool isEmpty();
    T firstEl();

    // MUTATORS
    void clearQueue();
    bool enQueue(T);
    T deQueue();

    // OTHER METHODS
    void printArray();

private:

    T *queueArray;
    int frontIndex;
    int backIndex;
    bool queueEmpty;
    bool queueFull;
};

#endif /* ARRAYQUEUE_H */

