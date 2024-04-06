//---------------------------------------------------------------
// CS 211 - Data Structures - Fall 2022 - Week 05 Lab Exercise
// A quick look at sorting algorithms
// Bubble Sort vs Insertion Sort vs Selection Sort
//
// by David C. Tuttle - Last modified 19 Sep 2022
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------------
// bubbleSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void bubbleSort(int data[], int size) {
    int i, j, tmp;
    bool hasSwapped;

    int comps = 0;
    int swaps = 0;

    for (i = size; i > 0; i--) {
        hasSwapped = false;
        for (j = 0; j < i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                hasSwapped = true;
                swaps++;
            }
            comps++;
        }
        if (hasSwapped == false)
             break;
    }

    cout << "Total Comparisons: " << comps << endl;
    cout << "Total Swaps: " << swaps << endl;
}

//---------------------------------------------------------------
// insertionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged into sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void insertionSort(int data[], int size) {
    int i, j, tmp;

    int comps = 0;
    int swaps = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j > 0; j--) {
            
            comps++;
            
            if (data[j] < data[j - 1]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data [j - 1] = tmp;
                swaps++;
            }
            
            else break;

        }
    }

    cout << "Total Comparisons: " << comps << endl;
    cout << "Total Swaps: " << swaps << endl;
}

//---------------------------------------------------------------
// selectionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void selectionSort(int data[], int size) {
    int i, j, tmp, least;

    int comps = 0;
    int swaps = 0;

    for (i = 0; i < size; i++) {
        least = i;
        for (j = i + 1; j < size; j++) {
            if (data[j] < data[least]) {
                least = j;
            }

            comps++;
            
        }
        if (least != i) {
            tmp = data[least];
            data[least] = data[i];
            data[i] = tmp;
            swaps++;
        }
    }

    cout << "Total Comparisons: " << comps << endl;
    cout << "Total Swaps: " << swaps << endl;
}
