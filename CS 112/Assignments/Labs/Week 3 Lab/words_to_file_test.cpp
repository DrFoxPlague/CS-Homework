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
#include <fstream>
#include "words_to_file.h"
using namespace std;

int main()
{
    cout << boolalpha;

    
        
        cout << "then if the user enters" << endl; 
        
        cout << "cabbage\npotato\narmadillo" << endl;
        
        cout << "this will create a file with those three words written in it on seperate lines and return 3" << endl;
        cout << (words_to_file("lab3-1.txt", 3) == 3) << endl;
        

        
        cout << "then if the user enters" << endl;
        
        cout << "What\nare\nwe\ngonna\ndo?" << endl;

        cout << "this will create a file with those three words written in it on seperate lines and return 5" << endl;
        
        cout << (words_to_file("lab3-2.txt", 5) == 5) << endl;

    return EXIT_SUCCESS;
}

