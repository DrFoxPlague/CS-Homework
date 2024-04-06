/*--- 
    SECOND VERSION: for a separately-compiled C++ program

    COPY this into a .cpp file in a folder within the CS50 IDE 

    to compile: in a CS50 terminal that is open to the folder
        CONTAINING this program's .cpp files, type:
   
        g++ <my-program>.cpp <another-funct>.cpp ...  -o <my-program>

        (assuming this main function is in a file named my_program.cpp)
        (including the .cpp or .o files for *EVERY* function or class INVOLVED
        in this program)

    to run: in that same CS50 terminal that is open to the folder
        CONTAINING this .cpp file, type:

        ./<my-program>

    last modified: 2/4/22
---*/

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
#include "show_words.h"
using namespace std;

int main()
{
    cout << boolalpha;

    string names[3] = {"Jack", "Jill", "Mary"};
    string pie[5] = {"Apple", "Blueberry", "Pecan", "Pumpkin", "Cherry"};

    cout << "*** Testing show_words ***" << endl;
    
    cout << "Should see to the screen: Jack, Jill, Mary numbered on individual lines as well as the true value" << endl;
    cout << (show_words(names, 3) == 3) << endl;
    
    cout << "Should see to the screen: Apple, Blueberry, Pecan, Pumpkin, Cherry numbered on individual lines as well as the true value" << endl;
    cout << (show_words(pie, 5) == 5) << endl;

    return EXIT_SUCCESS;
}

