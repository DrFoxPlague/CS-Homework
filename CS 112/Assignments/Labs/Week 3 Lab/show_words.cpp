/*----
  signature: show_words : string[] int -> int
  purpose: This expects an array of words and has a side effect of printing each word on its own individual
           line, then returns the number of words printed to the screen. 
  tests:
        for
        string names[3] = {"Jack", "Jill", "Mary"};
        show_words(names, 3) == 3
        
        then has a side effect of printing to the screen:
        
        1: Jack
        2: Jill
        3: Mary
        
        for
        string pie[5] = {"Apple", "Blueberry", "Pecan", "Pumpkin", "Cherry"};
        show_words(pie, 5) == 5
        
        then has a side effect of printing to the screen:
        
        1: Apple
        2: Blueberry
        3: Pecan
        4: Pumpin
        5: Cherry

  by: Dakota Donner, Peter Ramos
  last modified: 2/4/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
// #include "something.h"    // uncomment and add as needed
using namespace std;

int show_words(string word_array[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout << i+1 << ": " << word_array[i] << endl;
    }
    return size;
}

