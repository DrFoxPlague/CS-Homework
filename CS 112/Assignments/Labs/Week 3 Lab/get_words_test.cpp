/*----
  signature: main: void -> int
  purpose: either:
           testing program for the function <name>
           OR
           <describe the program being written --
           what it needs, if anything, and what it does>

  by: Peter Ramos, Dakota Donner
  last modified: 2/4/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "get_words.h"
using namespace std;

int main()
{
    cout << boolalpha;
    
    cout << "*** Testing get_words ***" << endl;
    
    string things[3];
    string question[5];

    cout << (get_words("lab3-1.txt", things, 3) == 3) << endl;
    cout << (get_words("lab3-2.txt", question, 5) == 5) << endl;

    return EXIT_SUCCESS;
}

